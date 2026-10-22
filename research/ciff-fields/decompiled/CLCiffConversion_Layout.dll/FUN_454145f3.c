// Source: CLCiffConversion_Layout.dll @ 454145f3; FUN_454145f3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_454145f3(void *this,int *param_1)

{
  BSTR pOVar1;
  void *pvVar2;
  undefined1 uVar3;
  bool bVar4;
  int extraout_EAX;
  BSTR pOVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  BSTR pOVar9;
  int *piVar10;
  int *piVar11;
  BSTR local_74;
  undefined4 local_70;
  int *local_6c;
  undefined4 local_68;
  int *local_64;
  undefined4 local_60;
  BSTR local_5c;
  int local_58;
  BSTR local_54;
  BSTR local_50;
  void *local_4c;
  int local_48;
  int local_44;
  int local_40;
  void *local_3c;
  void *local_38;
  int local_34;
  int local_30;
  int local_2c;
  void *local_28;
  int *local_24;
  BSTR local_20;
  int local_1c;
  void *local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0;
  local_24 = (int *)0x0;
  local_18 = this;
  FUN_45404ce5(&local_24,(int *)((int)this + 0x6c));
  piVar10 = local_24;
  local_28 = (void *)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*local_24 + 0x34))(local_24,&local_28);
  FUN_45421dd2(this,(int)local_28,'\0',(void *)0x1);
  local_58 = 0;
  local_2c = extraout_EAX;
  pOVar5 = (BSTR)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8._0_1_ = 2;
  local_70 = 0;
  local_5c = pOVar5;
  local_74 = (BSTR)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8._0_1_ = 3;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 3;
  piVar11 = (int *)*param_1;
  if (piVar11 != param_1) {
    do {
      local_3c = (void *)piVar11[2];
      local_38 = local_3c;
      if (local_3c != (void *)0x0) {
        pOVar5 = *(BSTR *)((int)local_3c + 4);
        local_54 = pOVar5;
        if (pOVar5 != (BSTR)0x0) {
          (**(code **)(*(int *)pOVar5 + 4))(pOVar5);
          local_20 = (BSTR)0x0;
          local_8._0_1_ = 5;
          iVar6 = (**(code **)(*(int *)pOVar5 + 0x68))(pOVar5,&local_20);
          if (((-1 < iVar6) && (bVar4 = FUN_45402d4b(&local_20,L"TabField"), !bVar4)) &&
             (bVar4 = FUN_45406d42((int)local_3c), bVar4)) {
            FUN_4541222d(&local_74,(int *)local_74,&local_38);
          }
          SysFreeString(local_20);
        }
        local_8._0_1_ = 3;
        if (pOVar5 != (BSTR)0x0) {
          (**(code **)(*(int *)pOVar5 + 8))(pOVar5);
        }
      }
      piVar11 = (int *)*piVar11;
      pOVar5 = local_5c;
      uVar3 = (undefined1)local_8;
    } while (piVar11 != param_1);
  }
  local_8._0_1_ = uVar3;
  FUN_45412166((int *)&param_1);
  pOVar9 = *(BSTR *)local_74;
  local_20 = pOVar9;
  if (pOVar9 != local_74) {
    do {
      local_28 = *(void **)(pOVar9 + 4);
      local_20 = pOVar9;
      if (local_58 != 0) {
        pvVar7 = (void *)FUN_4541cd30((int)local_28);
        pOVar1 = local_5c;
        pOVar5 = *(BSTR *)local_5c;
        local_3c = pvVar7;
        while ((pOVar5 != pOVar1 &&
               (iVar6 = FUN_4541cd30(*(int *)(pOVar5 + 4)), pOVar9 = local_20, iVar6 <= (int)pvVar7)
               )) {
          pOVar5 = *(BSTR *)pOVar5;
        }
      }
      FUN_4541222d(&local_5c,(int *)pOVar5,&local_28);
      pOVar9 = *(BSTR *)pOVar9;
      piVar10 = local_24;
      pOVar5 = local_5c;
      local_20 = pOVar9;
    } while (pOVar9 != local_74);
  }
  FUN_45412166((int *)&local_74);
  pOVar5 = *(BSTR *)local_5c;
  pOVar9 = local_5c;
  local_20 = pOVar5;
  if (pOVar5 != local_5c) {
    do {
      pvVar7 = *(void **)(pOVar5 + 4);
      local_1c = 0;
      local_4c = pvVar7;
      local_20 = pOVar5;
      local_14 = pvVar7;
      FUN_4541cbbe(pvVar7,&local_54);
      local_8._0_1_ = 6;
      local_34 = FUN_4541cb7f((int)pvVar7);
      iVar6 = FUN_4541cb40((int)pvVar7);
      local_40 = local_34 + -1 + (int)((float)iVar6 / (float)local_2c + DAT_45447488);
      local_3c = (void *)FUN_4541cd30((int)pvVar7);
      FUN_4541cd14((int)pvVar7);
      local_68 = 0;
      local_6c = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
      local_8._0_1_ = 7;
      local_60 = 0;
      local_64 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
      pvVar2 = local_3c;
      pOVar1 = *(BSTR *)pOVar9;
      local_8 = CONCAT31(local_8._1_3_,8);
      piVar11 = local_6c;
      pvVar7 = local_14;
      for (; local_6c = piVar11, pOVar1 != pOVar9; pOVar1 = *(BSTR *)pOVar1) {
        local_3c = *(void **)(pOVar1 + 4);
        local_28 = local_3c;
        if (pvVar7 != local_3c) {
          local_30 = FUN_4541cb7f((int)local_3c);
          iVar6 = FUN_4541cb40((int)local_28);
          local_44 = local_30 + -1 + (int)((float)iVar6 / (float)local_2c + DAT_45447488);
          local_38 = (void *)FUN_4541cd30((int)local_28);
          (**(code **)(**(int **)((int)local_28 + 4) + 100))(*(int **)((int)local_28 + 4),&local_48)
          ;
          if (((local_40 < local_30) || (local_44 < local_34)) && (local_48 != 1)) {
LAB_454148bf:
            pvVar7 = local_14;
            if ((int)local_38 < (int)pvVar2) goto LAB_454148d6;
          }
          else if ((int)local_38 < (int)pvVar2) {
            FUN_4541222d(&local_6c,local_6c,&local_3c);
            goto LAB_454148bf;
          }
          FUN_4541222d(&local_64,local_64,&local_3c);
          pvVar7 = local_14;
        }
LAB_454148d6:
        pOVar5 = local_20;
        piVar11 = local_6c;
      }
      piVar10 = (int *)*piVar11;
      iVar6 = local_1c;
      while (piVar10 != piVar11) {
        local_44 = piVar10[2];
        local_40 = FUN_4541cd30(local_44);
        iVar8 = FUN_4541cd14(local_44);
        piVar10 = (int *)*piVar10;
        pOVar9 = local_5c;
        pOVar5 = local_20;
        if (iVar6 < iVar8 + local_40) {
          iVar6 = iVar8 + local_40;
        }
      }
      local_1c = iVar6;
      FUN_45412166((int *)&local_6c);
      iVar8 = FUN_4541cd30((int)local_14);
      iVar8 = local_1c - iVar8;
      local_44 = iVar8;
      local_40 = FUN_4541cd14((int)local_14);
      FUN_4541cbbe(local_14,&local_50);
      local_8 = CONCAT31(local_8._1_3_,9);
      (**(code **)(**(int **)((int)local_14 + 4) + 0x30))(*(int **)((int)local_14 + 4),local_1c);
      iVar6 = local_44;
      piVar11 = local_64;
      if (-1 < iVar8) {
        for (piVar10 = (int *)*local_64; piVar10 != piVar11; piVar10 = (int *)*piVar10) {
          local_44 = piVar10[2];
          iVar8 = FUN_4541cd30(local_44);
          (**(code **)(**(int **)(local_44 + 4) + 0x30))
                    (*(int **)(local_44 + 4),iVar8 + local_40 + iVar6);
          pOVar9 = local_5c;
          pOVar5 = local_20;
        }
      }
      FUN_45412166((int *)&local_64);
      FUN_4541222d(&param_1,param_1,&local_4c);
      SysFreeString(local_50);
      FUN_454224ff((int *)&local_64);
      FID_conflict__free(local_64);
      FUN_454224ff((int *)&local_6c);
      FID_conflict__free(local_6c);
      local_8._0_1_ = 3;
      SysFreeString(local_54);
      pOVar5 = *(BSTR *)pOVar5;
      piVar10 = local_24;
      local_20 = pOVar5;
    } while (pOVar5 != pOVar9);
  }
  FUN_45412166((int *)&local_5c);
  FUN_454224ff((int *)&local_74);
  FID_conflict__free(local_74);
  FUN_454224ff((int *)&local_5c);
  FID_conflict__free(local_5c);
  local_8 = (uint)local_8._1_3_ << 8;
  (**(code **)(*piVar10 + 8))(piVar10);
  FUN_454224ff((int *)&param_1);
  FID_conflict__free(param_1);
  return 0;
}


