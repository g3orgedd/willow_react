// Source: CLCSGraphicBasedField.dll @ 41c135b9; FUN_41c135b9

void __fastcall FUN_41c135b9(int param_1)

{
  undefined1 local_5c [84];
  uint local_8;
  
  local_8 = DAT_41c3f5d0 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    GetObjectW(*(HANDLE *)(param_1 + 0x10),0x54,local_5c);
  }
  FUN_41c19fdc(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


