// Source: CLCSSmallBarcode.dll @ 4202aa79; FUN_4202aa79

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_4202aa79(void *this,int param_1,int param_2,int param_3,BSTR param_4,float param_5,HDC param_6,
            int param_7,BSTR param_8,LONG *param_9)

{
  LONG LVar1;
  uint uVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  BSTR pOVar6;
  LPSIZE ptVar7;
  undefined4 uVar8;
  char cVar9;
  int local_24 [3];
  tagSIZE local_18 [2];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  uVar8 = 0xffffffff;
  local_8 = 0;
  local_18[0].cy = (LONG)this;
  if (param_1 == 10) {
    pvVar3 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (pvVar3 == (void *)0x0) goto LAB_4202aba7;
    cVar9 = '\0';
LAB_4202ab98:
    piVar4 = FUN_42028cfb(pvVar3,param_2,param_3,cVar9,(uint)(param_5._0_1_ != '\0'));
  }
  else if (param_1 == 0xb) {
    pvVar3 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (pvVar3 != (void *)0x0) {
      cVar9 = '\x01';
      goto LAB_4202ab98;
    }
LAB_4202aba7:
    piVar4 = (int *)0x0;
  }
  else if (param_1 == 0xc) {
    pvVar3 = (void *)FUN_42067914(0x84c);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (pvVar3 == (void *)0x0) goto LAB_4202aba7;
    piVar4 = FUN_42027c0a(pvVar3,param_2,(uint)(param_5._0_1_ != '\0'));
  }
  else if (param_1 == 0xd) {
    pvVar3 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (pvVar3 == (void *)0x0) goto LAB_4202aba7;
    piVar4 = FUN_420285a6(pvVar3,param_2,param_3,(uint)(param_5._0_1_ != '\0'));
  }
  else {
    if (param_1 != 0xe) goto LAB_4202aca0;
    pvVar3 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (pvVar3 == (void *)0x0) goto LAB_4202aba7;
    piVar4 = FUN_4202914d(pvVar3,param_2,param_3,(uint)(param_5._0_1_ != '\0'));
  }
  uVar2 = local_8 >> 8;
  local_8 = local_8 & 0xffffff00;
  if (piVar4 != (int *)0x0) {
    local_24[0] = 0;
    local_24[1] = 0;
    local_24[2] = 0;
    local_8 = CONCAT31((int3)uVar2,6);
    iVar5 = (**(code **)(*piVar4 + 4))(&param_4,local_24,(int)this + 0x74);
    if (-1 < iVar5) {
      uVar8 = (**(code **)(*piVar4 + 8))();
      pOVar6 = param_8;
      if (param_7 < 1000) {
        pOVar6 = (BSTR)((param_7 * (int)param_8) / 1000);
      }
      if ((int)pOVar6 < 3) {
        pOVar6 = (BSTR)0x3;
      }
      (**(code **)(**(int **)(local_18[0].cy + 0xf8) + 0x2c))
                (*(int **)(local_18[0].cy + 0xf8),&param_5);
      *(int *)(local_18[0].cy + 0xa0) = (int)((double)(param_5 * _DAT_42093e98) + _DAT_42093e80);
      (**(code **)(**(int **)(local_18[0].cy + 0xf8) + 0x34))
                (*(int **)(local_18[0].cy + 0xf8),&param_5);
      *(int *)(local_18[0].cy + 0xa4) = (int)((double)(param_5 * _DAT_42093e98) + _DAT_42093e80);
      ptVar7 = FUN_4202a89b((void *)local_18[0].cy,local_18,(int)piVar4,param_6,pOVar6);
      LVar1 = ptVar7->cy;
      *param_9 = ptVar7->cx;
      param_9[1] = LVar1;
    }
    (**(code **)*piVar4)(1);
    FUN_420284e3(local_24);
  }
LAB_4202aca0:
  SysFreeString(param_4);
  return uVar8;
}


