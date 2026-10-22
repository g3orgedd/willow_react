// Source: CLCiffConversion_Layout.dll @ 45402cd0; FUN_45402cd0

void * __thiscall FUN_45402cd0(void *this,LPCSTR param_1)

{
  rsize_t rVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    rVar1 = 0;
  }
  else {
    rVar1 = lstrlenA(param_1);
  }
  FUN_45402f40(this,rVar1,param_1);
  return this;
}


