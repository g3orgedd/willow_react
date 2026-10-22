// Source: CLPrintPreview.ocx @ 3f4130f7; FUN_3f4130f7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

DWORD __thiscall FUN_3f4130f7(void *this,undefined4 *param_1,int *param_2,int param_3)

{
  int *piVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG local_70;
  int local_60;
  int local_5c;
  int local_58;
  BSTR local_54 [2];
  int *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x60;
  local_8 = 0x3f413103;
  if (param_2 == (int *)0x0) {
    DVar2 = 0x80004005;
  }
  else {
    local_4c = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    local_28 = 0;
    DVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,&local_28);
    if (-1 < (int)DVar2) {
      FUN_3f402fa5(&local_30);
      local_24 = 0;
      if (0 < local_28) {
        do {
          FUN_3f4272e0((uint *)&local_70,0,0x10);
          VariantInit(&local_70);
          local_24 = local_24 + 1;
          local_8._0_1_ = 2;
          DVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,local_24,&local_70);
          if ((int)DVar2 < 0) {
LAB_3f4134e9:
            VariantClear(&local_70);
            break;
          }
          CComQIPtr<>(&param_2,(undefined4 *)local_70.n1._8_4_);
          local_60 = 0;
          local_5c = 0;
          local_8._0_1_ = 3;
          DVar2 = (**(code **)(*param_2 + 0x2c))(param_2,&local_60);
          if (((int)DVar2 < 0) ||
             (DVar2 = (**(code **)(*param_2 + 0x34))(param_2,&local_5c), (int)DVar2 < 0)) {
LAB_3f4134d8:
            local_8._0_1_ = 2;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
            goto LAB_3f4134e9;
          }
          if (*(int *)((int)this + 0x130) == 0) {
            piVar5 = *(int **)((int)this + 0xe8);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 4))(piVar5);
            }
            local_60 = FUN_3f403cfa(local_60,0.0,piVar5);
            piVar5 = *(int **)((int)this + 0xe8);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 4))(piVar5);
            }
            local_5c = FUN_3f403cfa(local_5c + param_3,0.0,piVar5);
          }
          local_58 = 0;
          local_54[0] = (BSTR)0x0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          local_14[0] = 0;
          DVar2 = (**(code **)(*param_2 + 0x78))(param_2,&local_58);
          if (((((int)DVar2 < 0) ||
               (DVar2 = (**(code **)(*param_2 + 0x80))(param_2,local_54), (int)DVar2 < 0)) ||
              (DVar2 = (**(code **)(*param_2 + 0x3c))(param_2,&local_20), (int)DVar2 < 0)) ||
             (((DVar2 = (**(code **)(*param_2 + 0x44))(param_2,&local_1c), (int)DVar2 < 0 ||
               (DVar2 = (**(code **)(*param_2 + 0x4c))(param_2,&local_18), (int)DVar2 < 0)) ||
              (DVar2 = (**(code **)(*param_2 + 0x24))(param_2,local_14), (int)DVar2 < 0))))
          goto LAB_3f4134d8;
          if (*(int *)((int)this + 0x130) == 1) {
            local_58 = (int)(((float)local_58 * *(float *)((int)this + 0x13c)) /
                            *(float *)((int)this + 0x134));
            local_54[0] = (BSTR)(int)(((float)(int)local_54[0] * *(float *)((int)this + 0x140)) /
                                     *(float *)((int)this + 0x138));
          }
          else {
            piVar5 = *(int **)((int)this + 0xe8);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 4))(piVar5);
            }
            local_58 = FUN_3f403cfa(local_58,1.4013e-45,piVar5);
            piVar5 = *(int **)((int)this + 0xe8);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 4))(piVar5);
            }
            local_54[0] = (BSTR)FUN_3f403cfa((int)local_54[0],0.0,piVar5);
          }
          DVar2 = (**(code **)(*param_2 + 100))(param_2,&local_34);
          if ((int)DVar2 < 0) goto LAB_3f4134d8;
          if (local_34 == 0) {
            puVar3 = CComQIPtr<>(&local_48,param_2);
            local_8._0_1_ = 4;
            DVar2 = FUN_3f41402e(this,param_1,(OLECHAR *)*puVar3,local_60,local_5c,local_58,
                                 (int)local_54[0]);
            piVar5 = local_48;
LAB_3f4134a1:
            local_8._0_1_ = 3;
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 8))(piVar5);
            }
          }
          else {
            if (local_34 == 1) {
              puVar3 = CComQIPtr<>(&local_44,param_2);
              local_8._0_1_ = 5;
              DVar2 = FUN_3f412a2a(this,*param_1,(int *)*puVar3,local_60,local_5c,local_58,
                                   local_54[0]);
              piVar5 = local_44;
              goto LAB_3f4134a1;
            }
            if (local_34 == 2) {
              CComQIPtr<>(&local_2c,param_2);
              local_8._0_1_ = 6;
              (**(code **)(*local_2c + 0xb8))(local_2c,&local_38);
              if (local_38 == 1) {
                puVar3 = CComQIPtr<>(&local_3c,param_2);
                local_8 = CONCAT31(local_8._1_3_,7);
                DVar2 = FUN_3f41351a(this,*param_1,(int *)*puVar3,local_60,local_5c,local_58,
                                     (int)local_54[0]);
                piVar4 = local_3c;
              }
              else {
                puVar3 = CComQIPtr<>(&local_40,param_2);
                local_8 = CONCAT31(local_8._1_3_,8);
                DVar2 = FUN_3f413719(this,*param_1,(int *)*puVar3,local_60,local_5c,local_58,
                                     (int)local_54[0],local_20,local_1c,local_18,local_14[0]);
                piVar4 = local_40;
              }
              local_8._0_1_ = 6;
              piVar5 = local_2c;
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 8))(piVar4);
                piVar5 = local_2c;
              }
              goto LAB_3f4134a1;
            }
          }
          local_8._0_1_ = 2;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
          VariantClear(&local_70);
        } while (local_24 < local_28);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_3f40335c(&local_30);
    }
    local_8 = 0xffffffff;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return DVar2;
}


