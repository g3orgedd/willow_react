// Source: CLARiSOFT.exe @ 00e2bfe2; FUN_00e2bfe2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_00e2bfe2(void *this,LPCWSTR param_1,BSTR param_2,BSTR param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 *this_00;
  bool bVar1;
  UINT UVar2;
  HRESULT HVar3;
  char cVar4;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  int extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR extraout_ECX_03;
  BSTR pOVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  VARIANTARG local_3c;
  OLECHAR *local_2c;
  int local_28;
  BSTR local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  char local_12;
  char local_11;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  this_00 = (undefined4 *)((int)this + 0x1d8);
  local_8 = 2;
  SysFreeString((BSTR)*this_00);
  *this_00 = 0;
  UVar2 = SysStringLen(param_3);
  if (UVar2 != 0) {
    FUN_00e01fd0(this_00,(int *)&param_3);
  }
  if ((*(int *)((int)this + 0x19c) == 0) || (*(int *)((int)this + 0x15c) == 0)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
    local_1c = 1;
    if (0 < param_6) {
      do {
        FUN_00e03b51((uint *)&local_3c);
        local_8._0_1_ = 3;
        (**(code **)(**(int **)((int)this + 0x19c) + 0x24))();
        CComQIPtr<>(&local_18,(undefined4 *)local_3c.n1._8_4_);
        local_24 = (BSTR)0x0;
        local_8._0_1_ = 5;
        (**(code **)(**(int **)((int)this + 0x15c) + 0x1c))();
        bVar1 = ATL::CComBSTR::operator==
                          ((CComBSTR *)&param_1,(CComBSTR *)(*(int *)((int)this + 0x158) + 4));
        local_11 = '\x01' - bVar1;
        HVar3 = VarBstrCmp(param_2,local_24,0x400,0);
        cVar4 = HVar3 != 1;
        if (local_11 != '\0') {
          local_12 = '\x01';
          FUN_00e03bc2(&local_2c,param_1);
          local_8 = CONCAT31(local_8._1_3_,6);
          local_28 = FUN_00e050e5(*(void **)((int)this + 0x1e4),local_2c);
          pOVar5 = extraout_ECX;
          if (local_28 != 0) {
            bVar1 = ATL::CComBSTR::operator==
                              ((CComBSTR *)(local_28 + 8),
                               (CComBSTR *)(*(int *)((int)this + 0x158) + 8));
            if (!bVar1) {
              FUN_00e310e9(this,local_28);
            }
            *(int *)((int)this + 0x158) = local_28;
            FUN_00e353ea(this,(int *)(local_28 + 4));
            pOVar5 = extraout_ECX_00;
          }
          FUN_00e03ab8(&stack0xffffff9c,(int *)(*(int *)((int)this + 0x158) + 4));
          FUN_00e34ec9(pOVar5);
          FUN_00e30971((int)this);
          local_8._0_1_ = 5;
          FUN_00e01f81((int *)&local_2c);
          cVar4 = local_12;
        }
        if (cVar4 != '\0') {
          if (local_11 == '\0') {
            FUN_00e353ea(this,(int *)(*(int *)((int)this + 0x158) + 4));
          }
          FUN_00e28d47(this,(int *)&param_2);
        }
        *(undefined4 *)((int)this + 0x138) = param_5;
        *(undefined4 *)((int)this + 0x13c) = param_4;
        FUN_00e34f42((int)this);
        (**(code **)(*local_18 + 0x60))(local_18);
        (**(code **)(*local_18 + 0x68))(local_18,*(undefined4 *)((int)this + 0x138));
        pOVar5 = *(BSTR *)((int)this + 0x210);
        piVar8 = *(int **)((int)this + 0x20c);
        iVar7 = extraout_ECX_01;
        FUN_00e03ab8(&stack0xffffffa8,(int *)((int)this + 0x208));
        FUN_00e35557(this,iVar7,piVar8,pOVar5);
        CComQIPtr<>(&local_20,local_18);
        local_8._0_1_ = 7;
        pOVar5 = extraout_ECX_02;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 0xa0))();
          (**(code **)(*local_20 + 0xd0))();
          pOVar5 = extraout_ECX_03;
        }
        FUN_00e03ab8(&stack0xffffffb0,(int *)(*(int *)((int)this + 0x158) + 8));
        FUN_00e67d5d(*(void **)(*(int *)((int)this + 400) + -4 + local_1c * 4),pOVar5);
        FUN_00e35da9((int)this);
        local_8._0_1_ = 5;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))();
        }
        SysFreeString(local_24);
        local_8._0_1_ = 3;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        VariantClear(&local_3c);
        local_1c = local_1c + 1;
      } while (local_1c <= param_6);
    }
    FUN_00e2a1d4((int)this);
  }
  SysFreeString(param_1);
  SysFreeString(param_2);
  SysFreeString(param_3);
  return uVar6;
}


