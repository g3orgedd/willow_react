// Source: CiffMgr.dll @ 68104b14; FUN_68104b14

VARIANTARG * __cdecl FUN_68104b14(VARIANTARG *param_1,VARIANTARG *param_2,VARIANTARG *param_3)

{
  while (param_1 != param_2) {
    param_2 = param_2 + -1;
    param_3 = param_3 + -1;
    if (param_3 != param_2) {
      FUN_68104449(param_3,param_2);
    }
  }
  return param_3;
}


