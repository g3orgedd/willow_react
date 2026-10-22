// Source: CiffHelper.dll @ 40828cca; FUN_40828cca

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_40828cca(void *this,double *param_1,int *param_2,int *param_3,int *param_4,double *param_5)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  UINT UVar4;
  double *pdVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int local_68 [4];
  int local_58;
  double *local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48;
  double local_44;
  double *local_3c;
  int *local_38;
  BSTR local_34;
  double local_30;
  int *local_28;
  _union_2683 local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x40828cd6;
  local_54 = param_1;
  local_3c = param_5;
  local_38 = this;
  if (((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) || (param_4 == (int *)0x0)) {
    *param_1 = DAT_4084abe0;
  }
  else {
    local_34 = (BSTR)0x0;
    local_30 = DAT_4084abe0;
    local_8 = 0;
    (**(code **)(*param_4 + 0xbc))(param_4,&local_34);
    UVar4 = SysStringLen(local_34);
    if (((UVar4 != 0) && (bVar2 = FUN_40803ed6(&local_34,L"CurrentDate"), !bVar2)) &&
       (cVar3 = (**(code **)*param_2)(), cVar3 == '\0')) {
      FUN_40802e76((uint *)&local_24);
      local_8._0_1_ = 1;
      (**(code **)(*param_3 + 0x28))(param_3,local_34);
      if (local_24.n2.vt != 0) {
        CComQIPtr<>(&local_28,(undefined4 *)local_24._8_4_);
        local_8._0_1_ = 2;
        if (local_28 != (int *)0x0) {
          cVar3 = (**(code **)(*param_2 + 4))();
          if (cVar3 == '\0') {
            FUN_408293aa(&local_30,DAT_4084abe0);
          }
          else {
            pdVar5 = (double *)FUN_40828cca(local_38,&local_44,param_2,param_3,local_28,local_3c);
            local_30 = *pdVar5;
          }
        }
        local_8._0_1_ = 1;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))();
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      VariantClear((VARIANTARG *)&local_24.n2);
    }
    (**(code **)(*param_4 + 0x3c))(param_4,&local_48);
    (**(code **)(*param_4 + 0x34))(param_4,&local_50);
    (**(code **)(*param_4 + 0x2c))(param_4,&local_4c);
    (**(code **)(*param_4 + 0x24))(param_4,&local_58);
    if (local_58 == 0) {
      FUN_40829dc6(local_68,local_48,local_50,local_4c,0,0,0);
      bVar2 = FUN_40803ed6(&local_34,L"CurrentDate");
      pdVar5 = local_3c;
      if (!bVar2) {
        pdVar5 = &local_30;
      }
      pdVar5 = FUN_408294b5(&local_44,pdVar5,local_68);
      local_30 = *pdVar5;
      (**(code **)(*param_4 + 0x7c))(param_4);
      if (local_28 != (int *)0x0) {
        (**(code **)(*param_4 + 0x84))(param_4);
        local_3c = (double *)0x0;
        (**(code **)(*param_4 + 0x8c))(param_4,&local_3c);
        local_24._8_4_ = (undefined4 *)0x1;
        local_24.decVal.Hi32 = 0;
        local_24._12_4_ = 2;
        local_44 = local_30;
        FUN_4082a0ae(&local_44,*(uint *)((int)&local_24 + (int)local_28 * 4),
                     (local_38 != (int *)0x0) + 1,(uint)local_3c);
        FUN_408293aa(&local_30,local_44);
      }
    }
    else {
      FUN_40829d89(&local_44,(WORD)local_48,local_50,(WORD)local_4c,0,0,0);
      local_30 = local_44;
    }
    puVar6 = CComQIPtr<>(&local_38,param_4);
    local_8._0_1_ = 3;
    FUN_40828b86((int *)*puVar6,&local_30);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))();
    }
    (**(code **)(*param_4 + 0x48))(param_4,local_30);
    iVar1 = *param_4;
    uVar7 = FUN_40829763(&local_30);
    (**(code **)(iVar1 + 0xa8))(param_4,uVar7);
    iVar1 = *param_4;
    uVar7 = FUN_40829cd3(&local_30);
    (**(code **)(iVar1 + 0xb0))(param_4,uVar7);
    iVar1 = *param_4;
    uVar7 = FUN_4082a025(&local_30);
    (**(code **)(iVar1 + 0xb8))(param_4,uVar7);
    (**(code **)(*param_2 + 8))(param_4,&local_30);
    *local_54 = local_30;
    SysFreeString(local_34);
  }
  FUN_4082d4c6();
  return;
}


