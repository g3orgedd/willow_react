// Source: CLARiSOFT.exe @ 00e33899; FUN_00e33899

void __thiscall FUN_00e33899(void *this,undefined4 *param_1)

{
  HBRUSH hbr;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClipBox((HDC)*param_1,&local_18);
  InflateRect(&local_18,1,1);
  hbr = CreateSolidBrush(*(COLORREF *)((int)this + 0x170));
  FillRect((HDC)*param_1,&local_18,hbr);
  DeleteObject(hbr);
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


