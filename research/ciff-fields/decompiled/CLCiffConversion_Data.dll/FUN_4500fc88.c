// Source: CLCiffConversion_Data.dll @ 4500fc88; FUN_4500fc88

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4500fc88(void *this,undefined4 *param_1,void *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  int iVar7;
  VARIANTARG local_58;
  VARIANTARG local_48;
  int local_38;
  int local_34;
  int *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  LPCWSTR local_1c;
  int *local_18;
  char local_11;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x4500fc94;
  uVar5 = 0;
  bVar1 = false;
  iVar7 = 0;
  local_28 = 0;
  CComQIPtr<>(&local_30,*(undefined4 **)(*(int *)(*(int *)this + 4) + 0x34 + (int)this));
  local_8 = 0;
  FUN_45001f8d((uint *)&local_58);
  local_8._0_1_ = 1;
  if (local_30 != (int *)0x0) {
    iVar7 = (**(code **)(*local_30 + 0xcc))(local_30,&local_58);
  }
  CComQIPtr<>(&local_20,(undefined4 *)local_58.n1._8_4_);
  local_24 = 0;
  local_8._0_1_ = 2;
  if (local_20 != (int *)0x0) {
    iVar7 = (**(code **)(*local_20 + 0x1c))(local_20,&local_24);
    local_2c = 1;
    if (0 < local_24) {
      do {
        iVar6 = local_2c;
        if (iVar7 < 0) break;
        FUN_45001f8d((uint *)&local_48);
        local_8._0_1_ = 3;
        (**(code **)(*local_20 + 0x30))(local_20,iVar6,&local_48);
        CComQIPtr<>(&local_18,(undefined4 *)local_48.n1._8_4_);
        if (local_18 == (int *)0x0) {
          iVar7 = -0x7fffbffb;
        }
        else {
          local_1c = (LPCWSTR)0x0;
          local_8._0_1_ = 5;
          iVar7 = (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
          if (iVar7 < 0) {
LAB_4500fd9e:
            local_11 = '\0';
          }
          else {
            puVar3 = FUN_450020a5(&local_38,(LPCWSTR)*param_1);
            local_28 = uVar5 | 1;
            local_8 = CONCAT31(local_8._1_3_,6);
            puVar4 = FUN_450020a5(&local_34,local_1c);
            uVar5 = 3;
            bVar1 = true;
            local_8._0_1_ = 7;
            local_8._1_3_ = 0;
            local_28 = 3;
            bVar2 = FUN_450034f4((LPCWSTR)*puVar4,(ushort *)*puVar3);
            local_11 = '\x01';
            if (CONCAT31(extraout_var,bVar2) == 0) goto LAB_4500fd9e;
          }
          if ((uVar5 & 2) != 0) {
            uVar5 = uVar5 & 0xfffffffd;
            FUN_45002256(&local_34);
          }
          local_8._0_1_ = 5;
          local_8._1_3_ = 0;
          if (bVar1) {
            uVar5 = uVar5 & 0xfffffffe;
            bVar1 = false;
            FUN_45002256(&local_38);
          }
          if (local_11 != '\0') {
            SysFreeString((BSTR)*param_1);
            *param_1 = 0;
            (**(code **)(*local_18 + 0x34))(local_18,param_1);
            FUN_450022ba(param_2,(int *)&local_18);
            SysFreeString(local_1c);
            local_8._0_1_ = 3;
            if (local_18 != (int *)0x0) {
              (**(code **)(*local_18 + 8))(local_18);
            }
            VariantClear(&local_48);
            break;
          }
          SysFreeString(local_1c);
          iVar6 = local_2c;
        }
        local_8._0_1_ = 3;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear(&local_48);
        local_2c = iVar6 + 1;
      } while (local_2c <= local_24);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  VariantClear(&local_58);
  local_8 = 0xffffffff;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  return iVar7;
}


