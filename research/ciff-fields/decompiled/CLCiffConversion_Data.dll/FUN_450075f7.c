// Source: CLCiffConversion_Data.dll @ 450075f7; FUN_450075f7

int FUN_450075f7(uint param_1)

{
  uint3 uVar1;
  ushort *puVar2;
  
  puVar2 = &DAT_4503d9e0;
  do {
    uVar1 = (uint3)(byte)(*puVar2 >> 8);
    if (param_1 == *puVar2) {
      return CONCAT31(uVar1,1);
    }
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x4503d9ea);
  return (uint)uVar1 << 8;
}


