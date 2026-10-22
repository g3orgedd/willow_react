// Source: CLARiSOFT.exe @ 00e2d4d6; FUN_00e2d4d6

INT_PTR __thiscall FUN_00e2d4d6(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  INT_PTR IVar2;
  
  iVar1 = FUN_00e16126((void *)((int)this + 0x14),0,(void *)0x0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    IVar2 = -1;
  }
  else {
    FUN_00e14961(0xf40c34,(undefined4 *)((int)this + 8),this);
    IVar2 = DialogBoxParamW(DAT_00f44270,(LPCWSTR)0x145,param_1,FUN_00e26dc2,param_2);
  }
  return IVar2;
}


