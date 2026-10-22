// Source: CLCSSmallBarcode.dll @ 420031e5; FUN_420031e5

void * __thiscall FUN_420031e5(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_420033a8(this,iVar1,param_1);
  return this;
}


