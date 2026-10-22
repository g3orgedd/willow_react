// Source: CLCSSmallBarcode.dll @ 4202feda; FUN_4202feda

undefined4 FUN_4202feda(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_4 = 0;
  if ((param_2 < 3) || (iVar2 = _isdigit((uint)*(byte *)(param_1 + 2)), iVar2 == 0)) {
    *param_4 = 3;
    uVar3 = 5;
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 2) * 2 - 0x5c;
    *param_4 = uVar1;
    if (param_2 < uVar1) {
      *param_4 = param_2;
      uVar3 = 3;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


