// Source: CLCSSmallBarcode.dll @ 4200da54; FUN_4200da54

undefined4 __thiscall FUN_4200da54(void *this,uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 % 0x5a == 0) && (param_1 < 0x168)) {
    uVar1 = 0;
    if (param_1 == 0x5a) {
      uVar1 = FUN_4200d8b9(this);
    }
    else if (param_1 == 0xb4) {
      uVar1 = FUN_4200d59d(this);
    }
    else if (param_1 == 0x10e) {
      uVar1 = FUN_4200d742(this);
    }
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}


