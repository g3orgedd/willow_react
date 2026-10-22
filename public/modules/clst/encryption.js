const CLST_SEED = 0x26E20115;
const CLST_ALPHABET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!_";
const OUTPUT_BITS = 25;
const INPUTS_PER_NODE = 10;
const TRUTH_TABLE_SIZE = 1024;
const BITS_PER_CHAR = 16;
const CLST_SELECTOR_INPUT_COUNT = OUTPUT_BITS + BITS_PER_CHAR;

class CEncryption {
  constructor(key, seed = CLST_SEED, useKeyInputs = false) {
    // Native 68117DE2 copies a NUL-terminated key into a 15-WCHAR buffer.
    // Plaintext is a BSTR and does not have this NUL/14-unit restriction.
    this.key = String(key ?? "").split("\0", 1)[0].slice(0, 14);
    if (!this.key.length) throw new Error("CEncryption requires a non-empty key.");
    if (useKeyInputs) throw new Error("The confirmed ClSt CEncryption path uses useKeyInputs=false.");

    this.seed = Number(seed) >>> 0;
    this.useKeyInputs = false;
    this.truthTable = new Uint8Array(TRUTH_TABLE_SIZE);
    this.selectors = [];
    this.inputs = new Uint8Array(OUTPUT_BITS + (BITS_PER_CHAR * 2));
    this.outputs = new Uint8Array(OUTPUT_BITS);
    this.keyIndex = 0;
    this.currentState = 0;

    this.generateNetwork();
    for (let i = 0; i < this.key.length; i += 1) this.updateState(0);
  }

  rand15() {
    this.seed = (Math.imul(this.seed, 0x41C64E6D) + 0x3039) >>> 0;
    return (this.seed >>> 16) & 0x7FFF;
  }

  generateNetwork() {
    for (let i = 0; i < TRUTH_TABLE_SIZE; i += 1) {
      this.truthTable[i] = this.rand15() & 1;
    }

    for (let outputIndex = 0; outputIndex < OUTPUT_BITS; outputIndex += 1) {
      const selectedInputs = [];
      while (selectedInputs.length < INPUTS_PER_NODE) {
        const candidate = this.rand15() % CLST_SELECTOR_INPUT_COUNT;
        if (!selectedInputs.includes(candidate)) selectedInputs.push(candidate);
      }
      this.selectors.push(selectedInputs);
    }
  }

  updateState(plainWord) {
    const word = Number(plainWord) & 0xFFFF;

    for (let i = 0; i < OUTPUT_BITS; i += 1) this.inputs[i] = this.outputs[i];
    for (let i = 0; i < BITS_PER_CHAR; i += 1) {
      this.inputs[OUTPUT_BITS + i] = (word >> i) & 1;
    }

    const keyWord = this.key.charCodeAt(this.keyIndex);
    for (let i = 0; i < BITS_PER_CHAR; i += 1) {
      this.inputs[OUTPUT_BITS + BITS_PER_CHAR + i] = (keyWord >> i) & 1;
    }
    this.keyIndex = (this.keyIndex + 1) % this.key.length;

    const nextOutputs = new Uint8Array(OUTPUT_BITS);
    for (let outputIndex = 0; outputIndex < OUTPUT_BITS; outputIndex += 1) {
      let truthIndex = 0;
      for (let bitIndex = 0; bitIndex < INPUTS_PER_NODE; bitIndex += 1) {
        const inputIndex = this.selectors[outputIndex][bitIndex];
        if (this.inputs[inputIndex] !== 0) truthIndex |= 1 << bitIndex;
      }
      nextOutputs[outputIndex] = this.truthTable[truthIndex];
    }
    this.outputs = nextOutputs;

    let stateValue = 0;
    for (let i = 0; i < BITS_PER_CHAR; i += 1) {
      if (this.outputs[i]) stateValue |= 1 << i;
    }
    this.currentState = stateValue & 0xFFFF;
  }

  encryptWord(plainWord) {
    const word = Number(plainWord) & 0xFFFF;
    const oldState = this.currentState;
    this.updateState(word);
    return (oldState ^ word) & 0xFFFF;
  }

  encodeWord(value) {
    return CLST_ALPHABET[(value >> 11) & 0x1F] +
      CLST_ALPHABET[(value >> 5) & 0x3F] +
      CLST_ALPHABET[value & 0x1F];
  }

  encrypt(text) {
    const input = String(text ?? "");
    let result = "";
    for (let i = 0; i < input.length; i += 1) {
      result += this.encodeWord(this.encryptWord(input.charCodeAt(i)));
    }
    return result;
  }

  decrypt(encoded) {
    const input = String(encoded ?? "");
    if (!isClStEncodedText(input)) throw new Error("Invalid ClSt encoded UTF-16 triples.");
    let result = "";
    for (let offset = 0; offset < input.length; offset += 3) {
      const word = (CLST_ALPHABET.indexOf(input[offset]) << 11) |
        (CLST_ALPHABET.indexOf(input[offset + 1]) << 5) |
        CLST_ALPHABET.indexOf(input[offset + 2]);
      const plainWord = (word ^ this.currentState) & 0xFFFF;
      result += String.fromCharCode(plainWord);
      this.updateState(plainWord);
    }
    return result;
  }
}

function isClStEncodedText(value) {
  if (typeof value !== "string" || value.length % 3 !== 0) return false;
  for (let offset = 0; offset < value.length; offset += 3) {
    const first = CLST_ALPHABET.indexOf(value[offset]);
    const middle = CLST_ALPHABET.indexOf(value[offset + 1]);
    const last = CLST_ALPHABET.indexOf(value[offset + 2]);
    if (first < 0 || first > 31 || middle < 0 || last < 0 || last > 31) return false;
  }
  return true;
}

function encryptClStText(text, key) {
  return new CEncryption(key, CLST_SEED, false).encrypt(text);
}

function decryptClStText(text, key) {
  return new CEncryption(key, CLST_SEED, false).decrypt(text);
}

globalThis.CEncryption = CEncryption;
var CLST_ENCRYPTION_READY = true;
