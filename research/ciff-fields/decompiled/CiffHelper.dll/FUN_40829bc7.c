// Source: CiffHelper.dll @ 40829bc7; FUN_40829bc7

bool __cdecl FUN_40829bc7(LPSYSTEMTIME param_1,DOUBLE param_2)

{
  INT IVar1;
  
  IVar1 = VariantTimeToSystemTime(param_2,param_1);
  return IVar1 != 0;
}


