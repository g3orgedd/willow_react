// Source: CLCSSmallBarcode.dll @ 420301b7; FUN_420301b7

undefined4 FUN_420301b7(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  *param_4 = 0;
  if (param_2 != 0) {
    do {
      if (*(char *)(*param_4 + param_1) == -0x6f) break;
      uVar1 = *param_4 + 1;
      *param_4 = uVar1;
    } while (uVar1 < param_2);
  }
  if ((*(char *)(*param_4 + param_1) == -0x6f) &&
     (uVar1 = *param_4 + 1, *param_4 = uVar1, uVar1 == param_2)) {
    uVar2 = 9;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


