// Source: CLARiSOFT.exe @ 00e487e5; FUN_00e487e5

void __thiscall FUN_00e487e5(void *this,HGLOBAL param_1)

{
  LPVOID pvVar1;
  
  FUN_00e494ff(this);
  *(HGLOBAL *)this = param_1;
  if (param_1 == (HGLOBAL)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = GlobalLock(param_1);
  }
  *(LPVOID *)((int)this + 4) = pvVar1;
  return;
}


