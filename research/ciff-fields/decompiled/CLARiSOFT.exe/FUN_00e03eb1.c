// Source: CLARiSOFT.exe @ 00e03eb1; FUN_00e03eb1

void * __thiscall FUN_00e03eb1(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_00e041d7(this,iVar1,param_1);
  return this;
}


