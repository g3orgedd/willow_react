// Source: CiffMgr.dll @ 6810ba00; FUN_6810ba00

undefined4
FUN_6810ba00(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_4 != (int *)0x0) {
    (**(code **)(*param_4 + 4))(param_4);
  }
  uVar1 = (**(code **)(*param_4 + 0xdc))(param_4,param_2,param_3,param_5);
  (**(code **)(*param_4 + 8))(param_4);
  return uVar1;
}


