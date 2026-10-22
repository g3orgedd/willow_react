// Source: CiffMgr.dll @ 6810b939; FUN_6810b939

int FUN_6810b939(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  int iVar1;
  int *local_8;
  
  FUN_6810aef2(&local_8);
  iVar1 = (**(code **)*local_8)(local_8,&DAT_68148be8,param_5);
  if (iVar1 < 0) {
    (**(code **)(*local_8 + 0xe4))(1);
    *param_5 = 0;
  }
  else {
    iVar1 = (**(code **)(*local_8 + 0xb8))(local_8,param_2,param_3,param_4);
  }
  return iVar1;
}


