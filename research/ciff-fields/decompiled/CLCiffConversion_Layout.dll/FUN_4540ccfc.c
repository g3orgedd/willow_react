// Source: CLCiffConversion_Layout.dll @ 4540ccfc; FUN_4540ccfc

void __thiscall FUN_4540ccfc(void *this,int param_1,int param_2,int param_3)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar4 = (param_2 + param_1) * 0x20;
  iVar3 = 0;
  iVar7 = *(int *)((int)this + 0x24);
  iVar5 = *(int *)(iVar7 + 8 + iVar4) - *(int *)((int)this + 0x100) >> 1;
  iVar5 = iVar5 + (uint)*(ushort *)(*(int *)((int)this + 0x90) + iVar5 * 2);
  if ((*(ushort *)(iVar7 + 4 + iVar4) & 0x400) == 0) {
    if (-1 < param_3) {
      pbVar2 = (byte *)(*(int *)((int)this + 0x6c) + iVar5 + param_3);
      do {
        if ((*pbVar2 & 2) == 0) break;
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + -1;
      } while (iVar3 <= param_3);
    }
    piVar1 = (int *)(iVar7 + 0x10 + iVar4);
    *piVar1 = *piVar1 - iVar3;
  }
  else {
    uVar6 = param_3 + 1;
    if (uVar6 < *(uint *)(iVar7 + 0x10 + iVar4)) {
      pbVar2 = (byte *)(*(int *)((int)this + 0x6c) + iVar5 + param_3);
      do {
        if ((*pbVar2 & 2) == 0) break;
        iVar3 = iVar3 + 1;
        pbVar2 = pbVar2 + -1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(iVar7 + 0x10 + iVar4));
    }
    piVar1 = (int *)(iVar7 + 0x14 + iVar4);
    *piVar1 = *piVar1 + iVar3;
    piVar1 = (int *)(*(int *)((int)this + 0x24) + 0x10 + iVar4);
    *piVar1 = *piVar1 - iVar3;
  }
  piVar1 = (int *)(*(int *)((int)this + 0x24) + 0xc + iVar4);
  *piVar1 = *piVar1 - iVar3;
  if (0 < iVar3) {
    iVar3 = 0;
    iVar4 = *(int *)((int)this + 0x24) + iVar4;
    iVar7 = *(int *)(iVar4 + 0x10);
    *(undefined4 *)(iVar4 + 0x18) = 0;
    if (0 < iVar7) {
      iVar5 = *(int *)(iVar4 + 0x14) << 2;
      do {
        iVar3 = iVar3 + *(int *)(*(int *)((int)this + 0x48) + iVar5);
        iVar5 = iVar5 + 4;
        *(int *)(iVar4 + 0x18) = iVar3;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  return;
}


