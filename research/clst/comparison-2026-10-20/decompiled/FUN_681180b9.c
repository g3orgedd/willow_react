// CiffMgr.dll entry=681180b9

uint __fastcall FUN_681180b9(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0xadc) * 0x41c64e6d + 0x3039;
  *(uint *)(param_1 + 0xadc) = uVar1;
  return uVar1 >> 0x10 & 0x7fff;
}


