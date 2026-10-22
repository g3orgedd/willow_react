// Source: CiffMgr.dll @ 68116dfe; FUN_68116dfe

int FUN_68116dfe(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    *param_2 = 0;
    iVar3 = FUN_6811581b(&param_2);
    piVar2 = param_2;
    if (-1 < iVar3) {
      FUN_6811538e(param_2 + 1,param_1);
      piVar2[2] = (int)(param_1 + 1);
      piVar2[3] = param_1[1];
      iVar3 = (**(code **)*piVar2)(piVar2,&DAT_68147750,piVar1);
    }
    if ((iVar3 != 0) && (piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 0x1c))(1);
    }
  }
  return iVar3;
}


