// Source: CLCSSmallBarcode.dll @ 4200b114; FUN_4200b114

int __thiscall FUN_4200b114(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)((int)this + 0x144c);
  iVar2 = 0;
  while( true ) {
    if (*piVar1 == 0) {
      *(int *)((iVar2 + 0x1b1) * 0xc + (int)this) = param_1;
      *(int *)((int)this + 0x147c) = *(int *)((int)this + 0x147c) + 1;
      return iVar2;
    }
    if (*piVar1 == param_1) break;
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 3;
    if (3 < iVar2) {
      return -1;
    }
  }
  return iVar2;
}


