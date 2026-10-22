// Source: CLARiSOFT.exe @ 00e2d266; FUN_00e2d266

void __thiscall FUN_00e2d266(void *this,int param_1)

{
  bool bVar1;
  HWND pHVar2;
  tagMSG local_20;
  
  pHVar2 = GetActiveWindow();
  if ((pHVar2 == (HWND)0x0) || (pHVar2 == *(HWND *)(DAT_00f40d8c + 4))) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((((*(char *)((int)this + 0x21c) != '\0') && (param_1 == 2)) &&
      (*(int *)((int)this + 0x1e8) == 4)) && (bVar1)) {
    PeekMessageW(&local_20,*(HWND *)(DAT_00f40d8c + 4),0x416,0x416,1);
    PostMessageW(*(HWND *)(DAT_00f40d8c + 4),0x416,0,0);
  }
  return;
}


