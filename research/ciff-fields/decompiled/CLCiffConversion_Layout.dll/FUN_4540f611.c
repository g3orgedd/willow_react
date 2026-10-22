// Source: CLCiffConversion_Layout.dll @ 4540f611; FUN_4540f611

void __thiscall FUN_4540f611(void *this,DOUBLE param_1)

{
  INT IVar1;
  
  *(DOUBLE *)((int)this + 0xb0) = param_1;
  FUN_45429f70((uint *)((int)this + 0xbc),0,0x10);
  IVar1 = VariantTimeToSystemTime(param_1,(LPSYSTEMTIME)((int)this + 0xbc));
  if (IVar1 == 0) {
    GetLastError();
    FUN_4540303d(0x454487ac);
  }
  return;
}


