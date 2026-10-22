// Source: CiffMgr.dll @ 68103b55; FUN_68103b55

VARIANTARG * __cdecl FUN_68103b55(VARIANTARG *param_1,VARIANTARG *param_2,VARIANTARG *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != param_1) {
      FUN_68104449(param_3,param_1);
    }
    param_3 = param_3 + 1;
  }
  return param_3;
}


