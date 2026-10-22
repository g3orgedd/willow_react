// Source: CiffMgr.dll @ 68124179; FUN_68124179

int __cdecl FUN_68124179(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  if (param_4 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    iVar2 = (**(code **)(*(int *)*param_1 + 0xbc))((int *)*param_1,param_3,param_4);
    if (-1 < iVar2) {
      if (*param_4 != 0) {
        iVar2 = (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,*param_4,0);
      }
      if (-1 < iVar2) {
        return iVar2;
      }
    }
    piVar1 = (int *)*param_4;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *param_4 = 0;
    }
  }
  return iVar2;
}


