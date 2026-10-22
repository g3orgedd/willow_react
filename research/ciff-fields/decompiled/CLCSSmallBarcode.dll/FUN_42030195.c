// Source: CLCSSmallBarcode.dll @ 42030195; FUN_42030195

undefined4 FUN_42030195(undefined4 param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_3 + 0x18);
  *param_4 = uVar1;
  if (param_2 < uVar1) {
    *param_4 = param_2;
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


