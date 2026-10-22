// Source: CLCiffConversion_Data.dll @ 45002365; FUN_45002365

void * __thiscall FUN_45002365(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_45002681(this,iVar1,param_1);
  return this;
}


