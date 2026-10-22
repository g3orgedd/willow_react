// Source: CiffMgr.dll @ 68104b95; FUN_68104b95

undefined4 * __cdecl FUN_68104b95(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  
  while( true ) {
    if (param_1 == param_2) {
      return param_1;
    }
    bVar1 = FUN_68104eb2(&stack0x0000000c,*param_1,param_1[1],(undefined4 *)param_1[2]);
    if (bVar1) break;
    param_1 = param_1 + 4;
  }
  return param_1;
}


