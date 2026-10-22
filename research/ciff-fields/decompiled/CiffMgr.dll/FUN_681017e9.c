// Source: CiffMgr.dll @ 681017e9; FUN_681017e9

undefined4 * __cdecl FUN_681017e9(undefined4 *param_1,int param_2,int *param_3)

{
  double dVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  uVar2 = DAT_68147458;
  *param_1 = ZipherDate::vftable;
  *(undefined8 *)(param_1 + 2) = uVar2;
  uVar3 = FUN_68101adf((double *)(param_2 + 8));
  if (((char)uVar3 != '\0') && (uVar3 = FUN_68101a9f(param_3), (char)uVar3 != '\0')) {
    *(double *)(param_1 + 2) = *(double *)(param_2 + 8);
    if (*param_3 != 0) {
      FUN_681019cc(param_1,(short)*param_3);
    }
    if (param_3[1] != 0) {
      FUN_681018a6(param_1,param_3[1]);
    }
    dVar1 = *(double *)(param_3 + 2);
    fVar4 = FUN_68101a71(*(double *)(param_1 + 2));
    fVar4 = FUN_68101b0a((double)(fVar4 + (float10)dVar1));
    FUN_681017b7(param_1,(double)fVar4);
  }
  return param_1;
}


