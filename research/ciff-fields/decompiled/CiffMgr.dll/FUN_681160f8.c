// Source: CiffMgr.dll @ 681160f8; FUN_681160f8

undefined4 FUN_681160f8(int param_1,int param_2)

{
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    param_2 = param_2 + -1;
    if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) break;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 4;
  }
  return 1;
}


