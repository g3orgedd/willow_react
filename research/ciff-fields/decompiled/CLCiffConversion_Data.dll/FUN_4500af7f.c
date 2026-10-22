// Source: CLCiffConversion_Data.dll @ 4500af7f; FUN_4500af7f

void * __thiscall FUN_4500af7f(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_450035a3(this,iVar1,param_1);
  return this;
}


