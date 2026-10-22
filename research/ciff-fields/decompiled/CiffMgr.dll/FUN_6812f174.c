// Source: CiffMgr.dll @ 6812f174; FUN_6812f174

short * __thiscall FUN_6812f174(void *this,int param_1)

{
  short *psVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  
  psVar1 = (short *)((int)this + 0xb5c);
  psVar3 = psVar1;
  psVar5 = psVar1;
  if (param_1 < 0) {
    *psVar1 = 0x2d;
    psVar5 = (short *)((int)this + 0xb5e);
    param_1 = -param_1;
    psVar3 = psVar5;
  }
  do {
    psVar6 = psVar3;
    iVar4 = param_1 / 10;
    *psVar6 = (short)(param_1 % 10) + 0x30;
    param_1 = iVar4;
    psVar3 = psVar6 + 1;
  } while (0 < iVar4);
  psVar6[1] = 0;
  do {
    sVar2 = *psVar6;
    *psVar6 = *psVar5;
    psVar6 = psVar6 + -1;
    *psVar5 = sVar2;
    psVar5 = psVar5 + 1;
  } while (psVar5 < psVar6);
  return psVar1;
}


