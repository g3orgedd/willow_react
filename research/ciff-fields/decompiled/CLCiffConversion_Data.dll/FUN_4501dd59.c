// Source: CLCiffConversion_Data.dll @ 4501dd59; FUN_4501dd59

bool __cdecl FUN_4501dd59(LPSYSTEMTIME param_1,DOUBLE param_2)

{
  INT IVar1;
  
  IVar1 = VariantTimeToSystemTime(param_2,param_1);
  return IVar1 != 0;
}


