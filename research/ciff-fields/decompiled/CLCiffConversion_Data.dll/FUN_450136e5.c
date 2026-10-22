// Source: CLCiffConversion_Data.dll @ 450136e5; FUN_450136e5

void __thiscall FUN_450136e5(void *this,DOUBLE param_1)

{
  INT IVar1;
  
  *(DOUBLE *)((int)this + 0xb0) = param_1;
  FUN_45021c10((uint *)((int)this + 0xbc),0,0x10);
  IVar1 = VariantTimeToSystemTime(param_1,(LPSYSTEMTIME)((int)this + 0xbc));
  if (IVar1 == 0) {
    GetLastError();
    FUN_4500b2ef(0x4503ebe0);
  }
  return;
}


