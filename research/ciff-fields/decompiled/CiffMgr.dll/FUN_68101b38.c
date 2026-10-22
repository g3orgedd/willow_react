// Source: CiffMgr.dll @ 68101b38; FUN_68101b38

bool __cdecl FUN_68101b38(LPSYSTEMTIME param_1,DOUBLE param_2)

{
  INT IVar1;
  
  IVar1 = VariantTimeToSystemTime(param_2,param_1);
  return IVar1 != 0;
}


