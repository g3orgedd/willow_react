// Source: CiffMgr.dll @ 6810b990; FUN_6810b990

int FUN_6810b990(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_8;
  
  FUN_6810aef2(&local_8);
  iVar1 = (**(code **)*local_8)(local_8,&DAT_68148be8,param_3);
  if (iVar1 < 0) {
    (**(code **)(*local_8 + 0xe4))(1);
    *param_3 = 0;
  }
  else {
    iVar1 = (**(code **)(*local_8 + 0xd8))(local_8,param_2,0,0);
  }
  return iVar1;
}


