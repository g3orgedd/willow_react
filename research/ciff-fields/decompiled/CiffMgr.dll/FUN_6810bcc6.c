// Source: CiffMgr.dll @ 6810bcc6; FUN_6810bcc6

int __fastcall FUN_6810bcc6(int param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  FUN_6810bd55((int)puVar1);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_6816703c = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar2 = FUN_681043fa((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar2 < 0) {
    DAT_6816707c = 1;
  }
  else {
    *puVar1 = 0x24;
  }
  return param_1;
}


