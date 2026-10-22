// Source: CLCSBarcodeField.dll @ 4144e1bd; FUN_4144e1bd

undefined4 __thiscall FUN_4144e1bd(void *this,uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 % 0x5a == 0) && (param_1 < 0x168)) {
    uVar1 = 0;
    if (param_1 == 0x5a) {
      uVar1 = FUN_4144e022(this);
    }
    else if (param_1 == 0xb4) {
      uVar1 = FUN_4144dd06(this);
    }
    else if (param_1 == 0x10e) {
      uVar1 = FUN_4144deab(this);
    }
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


