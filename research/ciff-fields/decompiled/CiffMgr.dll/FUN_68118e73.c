// Source: CiffMgr.dll @ 68118e73; FUN_68118e73

int FUN_68118e73(int param_1)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = GetTickCount();
  FUN_68134dba(DVar1);
  uVar2 = FUN_68134d99();
  return (int)uVar2 % param_1;
}


