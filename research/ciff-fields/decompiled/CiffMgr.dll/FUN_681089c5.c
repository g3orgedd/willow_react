// Source: CiffMgr.dll @ 681089c5; FUN_681089c5

undefined4 FUN_681089c5(int param_1,int param_2)

{
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    param_2 = param_2 + -1;
    if (*(int *)(param_1 + 0xc) == *(int *)(*(int *)(param_1 + 8) + 4)) break;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x10;
  }
  return 1;
}


