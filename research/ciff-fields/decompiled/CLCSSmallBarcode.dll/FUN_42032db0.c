// Source: CLCSSmallBarcode.dll @ 42032db0; FUN_42032db0

undefined4 __thiscall
FUN_42032db0(void *this,uint param_1,undefined4 *param_2,uint *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  *param_4 = 0;
  *param_3 = 0;
  cVar1 = *(char *)((int)this + 9);
  uVar7 = param_1;
  if (cVar1 != '\0') {
    if ((param_1 == 0) || (param_1 == *(int *)((int)this + 0x24) + 1U)) {
      *param_2 = 0;
      param_2[1] = 0;
      *param_4 = (*(char *)((int)this + 8) == '\0') + 1;
      *param_3 = 1;
      return 0;
    }
    uVar7 = param_1 - 1;
  }
  if (*(uint *)((int)this + 0x24) <= uVar7) {
    return 0x4022a;
  }
  iVar3 = *(int *)((int)this + 0xc) * uVar7;
  if (*(char *)((int)this + 8) != '\0') {
    if (*(int *)((int)this + 0x30) != 0) {
      uVar8 = (*(int *)(*(int *)((int)this + 0x30) + 0xc) + uVar7) % 0x34;
      iVar4 = *(int *)(*(int *)((int)this + 0x30) + 0x10);
      iVar2 = *(int *)(*(int *)((int)this + 0x30) + 0x14);
      if (cVar1 != '\0') {
        *param_2 = 1;
        param_2[*param_3 * 2 + 1] = 2;
        *param_3 = *param_3 + 1;
      }
      FUN_4203194b((int)param_2,param_3,*(undefined4 *)(&DAT_4209b0f8 + uVar8 * 4),6);
      uVar5 = *(uint *)((int)this + 0xc);
      param_1 = 0;
      if (uVar5 != 0) {
        puVar6 = (ushort *)((int)this + (iVar3 + 0x56a) * 2);
        do {
          if ((2 < (int)uVar5) && (param_1 == uVar5 - 2)) {
            FUN_4203194b((int)param_2,param_3,
                         *(undefined4 *)(&DAT_4209b1c8 + ((iVar4 + uVar7) % 0x34) * 4),6);
          }
          FUN_4203194b((int)param_2,param_3,
                       *(undefined4 *)(&DAT_42098568 + ((uint)*puVar6 + (uVar8 % 3) * 0x3a1) * 4),8)
          ;
          param_1 = param_1 + 1;
          uVar5 = *(uint *)((int)this + 0xc);
          puVar6 = puVar6 + 1;
        } while (param_1 < uVar5);
      }
      FUN_4203194b((int)param_2,param_3,
                   *(undefined4 *)(&DAT_4209b0f8 + ((iVar2 + uVar7) % 0x34) * 4),6);
      if (*param_3 < 0x25) {
        param_2[*param_3 * 2] = 1;
        param_2[*param_3 * 2 + 1] = 1;
        *param_3 = *param_3 + 1;
      }
      if ((*(char *)((int)this + 9) != '\0') && (*param_3 < 0x25)) {
        param_2[*param_3 * 2] = 1;
        param_2[*param_3 * 2 + 1] = 2;
        *param_3 = *param_3 + 1;
      }
    }
    goto LAB_4203309e;
  }
  uVar8 = uVar7 % 3;
  if (cVar1 == '\0') {
LAB_42032e2e:
    param_2[*param_3 * 2] = 0x8e4924b;
    param_2[*param_3 * 2 + 1] = 10;
    *param_3 = *param_3 + 1;
  }
  else {
    *param_2 = 2;
    param_2[*param_3 * 2 + 1] = 2;
    *param_3 = *param_3 + 1;
    if (*param_3 < 0x25) goto LAB_42032e2e;
  }
  uVar9 = 8;
  iVar4 = uVar8 * 0x3a1;
  uVar5 = FUN_4203312a(this,uVar7,uVar8);
  FUN_4203194b((int)param_2,param_3,*(undefined4 *)(&DAT_42098568 + ((uVar5 & 0xffff) + iVar4) * 4),
               uVar9);
  param_1 = 0;
  if (*(int *)((int)this + 0xc) != 0) {
    puVar6 = (ushort *)((int)this + (iVar3 + 0x56a) * 2);
    do {
      FUN_4203194b((int)param_2,param_3,*(undefined4 *)(&DAT_42098568 + ((uint)*puVar6 + iVar4) * 4)
                   ,8);
      param_1 = param_1 + 1;
      puVar6 = puVar6 + 1;
    } while (param_1 < *(uint *)((int)this + 0xc));
  }
  if (*(int *)((int)this + 0x18) == 0) {
    uVar9 = 8;
    uVar7 = FUN_4203331a(this,uVar7,uVar8);
    FUN_4203194b((int)param_2,param_3,
                 *(undefined4 *)(&DAT_42098568 + ((uVar7 & 0xffff) + iVar4) * 4),uVar9);
    if (*param_3 < 0x25) {
      param_2[*param_3 * 2] = 0x7259251;
      param_2[*param_3 * 2 + 1] = 9;
      *param_3 = *param_3 + 1;
    }
  }
  else if (*param_3 < 0x25) {
    param_2[*param_3 * 2] = 1;
    param_2[*param_3 * 2 + 1] = 1;
    *param_3 = *param_3 + 1;
  }
  if ((*(char *)((int)this + 9) != '\0') && (*param_3 < 0x25)) {
    param_2[*param_3 * 2] = 2;
    param_2[*param_3 * 2 + 1] = 2;
    *param_3 = *param_3 + 1;
  }
LAB_4203309e:
  *param_4 = 1;
  return 0;
}


