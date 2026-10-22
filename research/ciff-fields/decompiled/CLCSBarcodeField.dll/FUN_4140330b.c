// Source: CLCSBarcodeField.dll @ 4140330b; FUN_4140330b

void * __thiscall FUN_4140330b(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_4140379c(this,iVar1,param_1);
  return this;
}


