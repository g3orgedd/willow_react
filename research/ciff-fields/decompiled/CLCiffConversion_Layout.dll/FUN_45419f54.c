// Source: CLCiffConversion_Layout.dll @ 45419f54; FUN_45419f54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45419f54(void *this,int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  undefined4 extraout_EAX_02;
  void *extraout_EAX_03;
  undefined4 extraout_EAX_04;
  void *pvVar6;
  int *piVar7;
  undefined4 local_60;
  int *local_5c;
  undefined **local_58;
  int *local_54;
  undefined **local_50;
  int *local_4c;
  void *local_48;
  undefined4 local_44;
  void *local_40;
  undefined4 local_3c;
  int local_38;
  BSTR local_34;
  void *local_30;
  int local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 0;
  local_20 = (int *)0x0;
  local_14 = this;
  FUN_45404ce5(&local_20,(int *)((int)this + 0x6c));
  piVar1 = local_20;
  local_1c = 0;
  local_8._0_1_ = 1;
  (**(code **)(*local_20 + 0x34))(local_20,&local_1c);
  local_44 = 0;
  local_48 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8._0_1_ = 2;
  FUN_4541d1d8(this,(int *)&local_48);
  local_3c = 0;
  local_40 = (void *)FUN_45421efd((int *)0x0,(int *)0x0);
  local_8._0_1_ = 3;
  FUN_4541c7ab(&local_20,&local_40);
  piVar7 = (int *)*param_1;
  if (piVar7 != param_1) {
    local_30 = (void *)((int)this + 100);
    do {
      pvVar6 = (void *)piVar7[2];
      local_28 = pvVar6;
      puVar2 = FUN_4541cbbe(pvVar6,&local_34);
      local_8._0_1_ = 4;
      FUN_45407800(local_30,(wchar_t *)*puVar2);
      local_8._0_1_ = 3;
      SysFreeString(local_34);
      iVar3 = FUN_4541cb40((int)pvVar6);
      iVar4 = FUN_4541cd4c((int)local_28);
      local_24 = (int *)(iVar4 / param_3);
      local_18 = 0;
      iVar3 = (int)((float)iVar3 / (float)param_3 + DAT_45447488);
      (**(code **)(*piVar1 + 0x2c))(piVar1,&local_18);
      if ((int)local_24 < local_18) {
        local_24 = (int *)((int)local_24 + 1);
      }
      (**(code **)(**(int **)((int)local_28 + 4) + 100))(*(int **)((int)local_28 + 4),&local_38);
      pvVar6 = local_14;
      if (local_38 == 0) {
        local_18 = iVar3;
        if (iVar3 < 1) {
          local_18 = 1;
        }
        iVar3 = FUN_4541b921(&local_20,&local_40,(int)local_24,&local_18);
        local_2c = iVar3;
        FUN_45412a39(&local_60);
        local_8._0_1_ = 5;
        (**(code **)**(undefined4 **)((int)local_28 + 4))
                  (*(undefined4 **)((int)local_28 + 4),&DAT_454486ec,&local_5c);
        FUN_45421dd2(local_14,*(int *)(iVar3 + 4),'\0',(void *)0x1);
        local_28 = extraout_EAX_03;
        FUN_45421dd2(local_14,local_1c * local_18,'\0',(void *)0x1);
        (**(code **)(*local_5c + 0x38))(local_5c,local_28);
        (**(code **)(*local_5c + 0x84))(local_5c,extraout_EAX_04);
        (**(code **)(*local_5c + 0x8c))(local_5c,*(int *)(local_2c + 4) / local_1c + 1);
        pvVar6 = local_14;
        local_2c = *(int *)(local_2c + 8);
        FUN_4541555d(local_14,&local_60,(int *)&local_48,&local_2c);
        local_8._0_1_ = 3;
        if (local_5c != (int *)0x0) {
          (**(code **)(*local_5c + 8))(local_5c);
        }
      }
      else if (local_38 == 1) {
        local_18 = iVar3;
        if (iVar3 < 1) {
          local_18 = 1;
        }
        piVar5 = FUN_4541ba69(&local_20,&local_40,(int)local_24,&local_18);
        local_24 = piVar5;
        FUN_4541260c(&local_58);
        local_58 = CCIFFBarcodeField::vftable;
        local_8 = CONCAT31(local_8._1_3_,6);
        (**(code **)**(undefined4 **)((int)local_28 + 4))
                  (*(undefined4 **)((int)local_28 + 4),&DAT_45449f90,&local_54);
        FUN_45421dd2(local_14,piVar5[1],'\0',(void *)0x1);
        local_2c = extraout_EAX_01;
        FUN_45421dd2(local_14,local_1c * local_18,'\0',(void *)0x1);
        (**(code **)(*local_54 + 0x38))(local_54,local_2c);
        (**(code **)(*local_54 + 0x84))(local_54,extraout_EAX_02);
        (**(code **)(*local_54 + 0x8c))(local_54,local_24[1] / local_1c + 1);
        piVar5 = local_54;
LAB_4541a153:
        local_8._0_1_ = 3;
        pvVar6 = local_14;
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 8))(piVar5);
          pvVar6 = local_14;
        }
      }
      else if (local_38 == 2) {
        if (iVar3 < 1) {
          iVar3 = 1;
        }
        local_2c = 0;
        piVar5 = *(int **)((int)local_14 + 0x38);
        local_18 = iVar3;
        if ((piVar5 == (int *)0x0) ||
           ((**(code **)(*piVar5 + 0x2fc))(piVar5,&local_2c), local_2c == 0)) {
          piVar5 = FUN_4541b99a(&local_20,&local_40,(int)local_24,&local_18);
          local_24 = piVar5;
          FUN_45412630(&local_50);
          local_50 = CCIFFGFXField::vftable;
          local_8 = CONCAT31(local_8._1_3_,7);
          (**(code **)**(undefined4 **)((int)local_28 + 4))
                    (*(undefined4 **)((int)local_28 + 4),&DAT_4544a718,&local_4c);
          FUN_45421dd2(local_14,piVar5[1],'\0',(void *)0x1);
          local_28 = extraout_EAX;
          FUN_45421dd2(local_14,local_1c * local_18,'\0',(void *)0x1);
          (**(code **)(*local_4c + 0x38))(local_4c,local_28);
          FUN_4541f632(&local_50,extraout_EAX_00);
          (**(code **)(*local_4c + 0x8c))(local_4c,local_24[1] / local_1c + 1);
          piVar5 = local_4c;
          goto LAB_4541a153;
        }
      }
      FUN_45402cd0((void *)((int)pvVar6 + 100),"");
      piVar7 = (int *)*piVar7;
    } while (piVar7 != param_1);
  }
  FUN_45412128((int *)&local_48);
  FUN_454224ff((int *)&local_40);
  FID_conflict__free(local_40);
  FUN_454224ff((int *)&local_48);
  FID_conflict__free(local_48);
  local_8 = (uint)local_8._1_3_ << 8;
  (**(code **)(*piVar1 + 8))(piVar1);
  FUN_454224ff((int *)&param_1);
  FID_conflict__free(param_1);
  return 0;
}


