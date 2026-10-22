// Source: CLCiffConversion_Layout.dll @ 45419c08; FUN_45419c08

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_45419c08(void *this,int *param_1,undefined4 param_2,int param_3)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  float10 fVar9;
  undefined **local_50;
  int *local_4c;
  undefined **local_48;
  int *local_44;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int *local_34;
  int local_30;
  int local_2c;
  BSTR local_28;
  float local_24;
  int *local_20;
  void *local_1c;
  float local_18;
  void *local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0;
  iVar6 = 0;
  local_20 = (int *)0x0;
  local_1c = this;
  FUN_45404ce5(&local_20,(int *)((int)this + 0x6c));
  piVar4 = local_20;
  local_24 = 0.0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*local_20 + 0x24))(local_20,&local_24);
  fVar5 = local_24;
  fVar9 = FUN_45406d26((int)local_1c);
  local_24 = (float)fVar9;
  local_30 = (int)((float)(int)fVar5 / local_24 + DAT_45447488);
  FUN_4541f150((undefined4 *)((int)local_1c + 0x5c));
  this_00 = local_1c;
  piVar7 = (int *)*param_1;
  if (piVar7 != param_1) {
    do {
      local_14 = (void *)piVar7[2];
      if (local_14 != (void *)0x0) {
        puVar1 = FUN_4541cbbe(local_14,&local_28);
        local_8._0_1_ = 2;
        FUN_45407800((void *)((int)this_00 + 100),(wchar_t *)*puVar1);
        local_8 = CONCAT31(local_8._1_3_,1);
        SysFreeString(local_28);
        local_24 = (float)FUN_4541cd4c((int)local_14);
        iVar2 = FUN_4541cb40((int)local_14);
        if (iVar2 < 2) {
          local_18 = 1.4013e-45;
        }
        else {
          local_18 = (float)FUN_4541cb40((int)local_14);
        }
        (**(code **)(**(int **)((int)local_14 + 4) + 100))(*(int **)((int)local_14 + 4),&local_2c);
        if (local_2c == 0) {
          FUN_45412a39(&local_38);
          local_8._0_1_ = 3;
          iVar6 = (**(code **)**(undefined4 **)((int)local_14 + 4))
                            (*(undefined4 **)((int)local_14 + 4),&DAT_454486ec,&local_34);
          piVar4 = local_34;
          if (iVar6 < 0) goto LAB_45419ee8;
          bVar8 = local_34 == (int *)0x0;
          if (!bVar8) {
            iVar2 = FUN_4541d01d((int)&local_38);
            piVar4 = local_34;
            if (iVar2 != 2) {
              fVar9 = FUN_45406d26((int)this_00);
              local_14 = (void *)(float)fVar9;
              local_18 = (float)(int)((float)(int)local_18 * (float)local_14 + DAT_45447488);
              local_3c = 0;
              local_40 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
              local_8._0_1_ = 4;
              uVar3 = FUN_4541d1d8(this_00,(int *)&local_40);
              if ((char)uVar3 != '\0') {
                FUN_4541555d(this_00,&local_38,(int *)&local_40,(int *)&local_18);
                FUN_45412128((int *)&local_40);
              }
              iVar6 = FUN_4541cded((int)&local_38);
              fVar9 = FUN_45406d26((int)this_00);
              local_18 = (float)fVar9;
              iVar6 = (int)((float)iVar6 / local_18 + DAT_45447488);
              fVar5 = local_24;
              while (local_30 < iVar6 + (int)fVar5) {
                if ((int)fVar5 < 0) {
                  if (iVar6 <= param_3) break;
                  iVar6 = iVar6 + -1;
                }
                else {
                  fVar5 = (float)((int)fVar5 + -1);
                }
              }
              (**(code **)(*local_34 + 0x38))(local_34,fVar5);
              iVar6 = (**(code **)(*local_34 + 0x84))(local_34,iVar6);
              FUN_454224ff((int *)&local_40);
              FID_conflict__free(local_40);
              piVar4 = local_34;
            }
            goto LAB_45419ee8;
          }
        }
        else {
          if (local_2c == 1) {
            FUN_4541260c(&local_50);
            local_50 = CCIFFBarcodeField::vftable;
            local_8._0_1_ = 5;
            iVar6 = (**(code **)**(undefined4 **)((int)local_14 + 4))
                              (*(undefined4 **)((int)local_14 + 4),&DAT_45449f90,&local_4c);
            piVar4 = local_4c;
            if (-1 < iVar6) {
              bVar8 = true;
              if (local_4c == (int *)0x0) goto LAB_45419eea;
              (**(code **)(*local_4c + 0x38))(local_4c,local_24);
              iVar6 = (**(code **)(*local_4c + 0xbc))(local_4c,local_18);
              piVar4 = local_4c;
            }
          }
          else {
            if (local_2c != 2) goto LAB_45419ef6;
            FUN_45412630(&local_48);
            local_48 = CCIFFGFXField::vftable;
            local_8._0_1_ = 6;
            iVar6 = (**(code **)**(undefined4 **)((int)local_14 + 4))
                              (*(undefined4 **)((int)local_14 + 4),&DAT_4544a718,&local_44);
            piVar4 = local_44;
            if (-1 < iVar6) {
              bVar8 = true;
              if (local_44 == (int *)0x0) goto LAB_45419eea;
              iVar6 = (**(code **)(*local_44 + 0x38))(local_44,local_24);
              FUN_4541f632(&local_48,(int)local_18);
              piVar4 = local_44;
            }
          }
LAB_45419ee8:
          bVar8 = piVar4 == (int *)0x0;
        }
LAB_45419eea:
        local_8 = CONCAT31(local_8._1_3_,1);
        if (!bVar8) {
          (**(code **)(*piVar4 + 8))(piVar4);
        }
      }
LAB_45419ef6:
      piVar7 = (int *)*piVar7;
    } while (piVar7 != param_1);
    piVar4 = local_20;
    if (iVar6 < 0) goto LAB_45419f2f;
  }
  FUN_45402cd0((void *)((int)local_1c + 100),"");
  bVar8 = FUN_4541c6c2(&local_20);
  if (bVar8) {
    FUN_4541f69b((int *)&param_1);
  }
LAB_45419f2f:
  local_8 = local_8 & 0xffffff00;
  (**(code **)(*piVar4 + 8))(piVar4);
  FUN_454224ff((int *)&param_1);
  FID_conflict__free(param_1);
  return iVar6;
}


