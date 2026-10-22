// Source: CLCiffConversion_Layout.dll @ 4540b7ec; FUN_4540b7ec

int __thiscall FUN_4540b7ec(void *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_8;
  
  if (*(char *)((int)this + 0x128) == '\0') {
    iVar2 = 0;
  }
  else {
    piVar1 = *(int **)((int)this + 0x124);
    iVar2 = 0;
    local_8 = 0;
    if ((piVar1[1] - *piVar1) / 0xc != 0) {
      iVar3 = *piVar1;
      iVar4 = 0;
      iVar5 = iVar2;
      do {
        iVar2 = ((int *)(iVar4 + iVar3))[2];
        if (param_2 < *(int *)(iVar4 + iVar3) - (param_1 - *(int *)((int)this + 0x100) >> 1)) {
          return iVar5;
        }
        iVar4 = iVar4 + 0xc;
        local_8 = local_8 + 1;
        iVar3 = *piVar1;
        iVar5 = iVar2;
      } while (local_8 < (uint)((piVar1[1] - *piVar1) / 0xc));
    }
  }
  return iVar2;
}


