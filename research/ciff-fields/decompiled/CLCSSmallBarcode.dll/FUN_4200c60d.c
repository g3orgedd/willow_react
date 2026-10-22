// Source: CLCSSmallBarcode.dll @ 4200c60d; FUN_4200c60d

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_4200c60d(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  int *local_8;
  
  iVar2 = (**(code **)(*param_1 + 0x14))((int)this + 0x2c4,&local_8);
  if ((-1 < iVar2) && (param_1 = (int *)0x0, local_8 != (int *)0x0)) {
    iVar6 = 0;
    do {
      iVar1 = *(int *)((int)this + 0x2c4);
      if ((*(int *)((int)this + 0x2c) == 0) || (*(int *)((int)this + 0x2c) == 0xb4)) {
        iVar4 = *(int *)((int)this + 0x14);
      }
      else {
        iVar4 = *(int *)((int)this + 0x10);
      }
      dVar7 = (double)*(int *)((int)this + 0x4c) / DAT_42089818;
      if ((dVar7 < DAT_4208a888) ||
         ((dVar8 = DAT_4208a1a8, dVar7 <= DAT_4208a1a8 && (dVar8 = dVar7, dVar7 < DAT_4208a888)))) {
        dVar8 = DAT_4208a888;
      }
      uVar5 = *(int *)(iVar1 + iVar6) * *(int *)((int)this + 0xf8) + *(int *)((int)this + 0x84);
      iVar4 = *(int *)(iVar1 + 8 + iVar6) * *(int *)((int)this + 0xe8) +
              (int)(dVar8 * ((double)iVar4 * _DAT_4208a898 + DAT_42089808));
      if (*(int *)((int)this + 0x3c) == 0) {
        iVar3 = (*(int *)((int)this + 0x78) - iVar4) + *(int *)((int)this + 0x88);
      }
      else {
        iVar3 = *(int *)((int)this + 0x88);
      }
      FUN_420270ab((void *)((int)this + 4),
                   (uint *)(*(int *)((int)this + 0xa0) +
                           (((*(int *)((int)this + 0x94) - iVar3) + -1) * *(int *)((int)this + 4) +
                           ((int)(uVar5 + ((int)uVar5 >> 0x1f & 0x1fU)) >> 5)) * 4),uVar5 & 0x1f,
                   *(int *)(iVar1 + 4 + iVar6) * *(int *)((int)this + 0xf8),iVar4);
      iVar6 = iVar6 + 0xc;
      param_1 = (int *)((int)param_1 + 1);
    } while (param_1 < local_8);
  }
  return iVar2;
}


