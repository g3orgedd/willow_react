// Source: CiffHelper.dll @ 4081bdba; FUN_4081bdba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4081bdba(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  bool bVar2;
  UINT UVar3;
  BSTR pOVar4;
  int *piVar5;
  double *pdVar6;
  undefined4 uVar7;
  HRESULT HVar8;
  int iVar9;
  int *piVar10;
  undefined1 local_78 [16];
  VARIANTARG local_68;
  VARIANTARG local_58;
  double local_48;
  OLECHAR local_40 [4];
  double local_38 [2];
  int local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x68;
  local_8 = 0x4081bdc6;
  CComQIPtr<>(&local_1c,param_3);
  local_8 = 0;
  FUN_40802e76((uint *)&local_68);
  local_8._0_1_ = 1;
  (**(code **)(*local_1c + 100))();
  CComQIPtr<>(&local_20,(undefined4 *)local_68.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(*local_20 + 0x1c))();
  iVar9 = 0;
  if (0 < local_24) {
    do {
      FUN_40802e76((uint *)&local_58);
      iVar9 = iVar9 + 1;
      local_8._0_1_ = 3;
      (**(code **)(*local_20 + 0x30))(local_20,iVar9);
      CComQIPtr<>(local_14,(undefined4 *)local_58.n1._8_4_);
      local_18 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,5);
      (**(code **)(*local_14[0] + 0xbc))(local_14[0],&local_18);
      UVar3 = SysStringLen(local_18);
      if (UVar3 != 0) {
        bVar2 = FUN_40803ed6(&local_18,L"CurrentDate");
        if (bVar2) {
          (**(code **)(*local_14[0] + 0x24))(local_14[0]);
          if (local_28 != 0) {
            bVar2 = FUN_4081c006(local_14);
            if (!bVar2) {
              FUN_40805bf7(local_38);
              bVar2 = FUN_4081d4ef();
              if (bVar2) {
                piVar5 = local_14[0];
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 4))(local_14[0]);
                }
                piVar10 = local_1c;
                if (local_1c != (int *)0x0) {
                  (**(code **)(*local_1c + 4))(local_1c);
                }
                pOVar4 = FUN_4080e73f(local_40,piVar10,piVar5);
                piVar5 = FUN_4080e725(local_78,*(int *)pOVar4);
                pdVar6 = FUN_408294b5(&local_48,local_38,piVar5);
                local_38[0] = *pdVar6;
              }
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              FUN_40829763(local_38);
              (**(code **)(iVar1 + 0x30))(piVar5);
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              uVar7 = FUN_40829cd3(local_38);
              (**(code **)(iVar1 + 0x38))(piVar5,uVar7);
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              uVar7 = FUN_4082a025(local_38);
              (**(code **)(iVar1 + 0x40))(piVar5,uVar7);
              (**(code **)(*local_14[0] + 0x48))(local_14[0],local_38[0]);
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              uVar7 = FUN_40829763(local_38);
              (**(code **)(iVar1 + 0xa8))(piVar5,uVar7);
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              uVar7 = FUN_40829cd3(local_38);
              (**(code **)(iVar1 + 0xb0))(piVar5,uVar7);
              piVar5 = local_14[0];
              iVar1 = *local_14[0];
              uVar7 = FUN_4082a025(local_38);
              (**(code **)(iVar1 + 0xb8))(piVar5,uVar7);
            }
          }
        }
      }
      SysFreeString(local_18);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))();
      }
      VariantClear(&local_58);
    } while (iVar9 < local_24);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  HVar8 = VariantClear(&local_68);
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    HVar8 = (**(code **)(*local_1c + 8))();
  }
  return CONCAT31((int3)((uint)HVar8 >> 8),1);
}


