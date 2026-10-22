// Source: CiffMgr.dll @ 6810b881; FUN_6810b881

int * FUN_6810b881(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  piVar2 = FUN_6810aef2(&local_8);
  piVar1 = local_8;
  if ((int)piVar2 < 0) {
    *param_2 = 0;
  }
  else {
    (**(code **)(*local_8 + 4))(local_8);
    piVar2 = (int *)(**(code **)*piVar1)(piVar1,&DAT_68148be8,param_2);
    (**(code **)(*piVar1 + 8))(piVar1);
    if ((int)piVar2 < 0) {
      (**(code **)(*piVar1 + 0xe4))(1);
      *param_2 = 0;
    }
  }
  return piVar2;
}


