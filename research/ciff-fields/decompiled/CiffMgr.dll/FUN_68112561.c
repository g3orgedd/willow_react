// Source: CiffMgr.dll @ 68112561; FUN_68112561

undefined4 FUN_68112561(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4;
    uVar1 = 0;
  }
  return uVar1;
}


