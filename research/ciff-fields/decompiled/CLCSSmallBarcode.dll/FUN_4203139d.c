// Source: CLCSSmallBarcode.dll @ 4203139d; FUN_4203139d

int __thiscall FUN_4203139d(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)this + 0x24) * param_1;
  if (*(char *)((int)this + 9) != '\0') {
    iVar2 = 4;
    if (*(char *)((int)this + 8) != '\0') {
      iVar2 = 2;
    }
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}


