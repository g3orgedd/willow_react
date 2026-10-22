// Source: CLCSTextBasedField.dll @ 42403baf; FUN_42403baf

void * __thiscall FUN_42403baf(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_42403f2b(this,iVar1,param_1);
  return this;
}


