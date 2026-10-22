// Source: CLCiffConversion_Data.dll @ 4501a5fa; FUN_4501a5fa

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4501a5fa(void *this,int *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  bool bVar3;
  int iVar4;
  UINT UVar5;
  OLECHAR ****ppppOVar6;
  undefined4 *puVar7;
  wchar_t *this_00;
  int *piVar8;
  int local_8c;
  int *local_88;
  BSTR local_84;
  BSTR local_80;
  char local_79;
  BSTR local_78;
  wchar_t local_74 [12];
  wchar_t local_5c [12];
  WCHAR local_44 [12];
  OLECHAR ***local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_8 = 0x4501a606;
  local_88 = param_1;
  if (param_1 == (int *)0x0) goto LAB_4501aa4d;
  (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,&local_84);
  local_80 = (BSTR)((uint)local_80 & 0xffffff00);
  bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                       L"Print Preview");
  if ((bVar3) ||
     (bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                           L"JobSelection"), bVar3)) {
    local_80 = (BSTR)CONCAT31(local_80._1_3_,1);
  }
  else {
    bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                         L"Capi");
    if (bVar3) {
      local_80 = (BSTR)CONCAT31(local_80._1_3_,
                                *(undefined1 *)
                                 (*(int *)(*(int *)((int)this + -0xc) + 4) + 0x39 + (int)this));
    }
  }
  local_79 = FUN_4501b95f(param_1);
  if ((bool)local_79) {
    FUN_4501c0b8((void *)((int)this + -0x10),param_1);
  }
  if (local_84 == (BSTR)0x0) {
    iVar4 = FUN_4500fc6d(param_1);
    if (iVar4 == 8) {
      FUN_4501ac15((void *)((int)this + -0x10),param_1);
    }
    else if (local_79 == '\0') {
      local_78 = (BSTR)0x0;
      local_8 = 1;
      (**(code **)(*(int *)*param_1 + 0x58))((int *)*param_1,&local_78);
      bVar3 = FUN_450023b0((void *)((int)this + -4),L"StaticGraphic");
      if (((bVar3) && (local_78 != (BSTR)0x0)) && (UVar5 = SysStringLen(local_78), UVar5 != 0)) {
        basic_string<>(local_44,local_78);
        local_1c = 0;
        local_18 = 7;
        local_2c[0] = (OLECHAR ***)((uint)local_2c[0] & 0xffff0000);
        local_8._0_1_ = 3;
        iVar4 = FUN_45009d9a(local_44,(LPCWSTR)local_2c);
        if (-1 < iVar4) {
          basic_string<>(local_5c,local_78);
          piVar8 = (int *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 200);
          iVar4 = *piVar8;
          piVar8 = (int *)FUN_45007e32(piVar8,&local_8c,local_5c);
          iVar1 = *piVar8;
          FUN_450046d9(local_5c,'\x01',0);
          param_1 = local_88;
          if (iVar1 == iVar4) {
            basic_string<>(local_74,local_78);
            local_8._0_1_ = 4;
            ppppOVar6 = local_2c;
            if (7 < local_18) {
              ppppOVar6 = (OLECHAR ****)local_2c[0];
            }
            puVar7 = FUN_45001f5d(&local_84,(OLECHAR *)ppppOVar6);
            pwVar2 = (wchar_t *)*puVar7;
            local_8._0_1_ = 5;
            this_00 = FUN_45008a59((void *)((int)this +
                                           *(int *)(*(int *)((int)this + -0xc) + 4) + 200),local_74)
            ;
            FID_conflict_assign(this_00,pwVar2);
            SysFreeString(local_84);
            FUN_450046d9(local_74,'\x01',0);
            param_1 = local_88;
          }
        }
        FUN_450046d9(local_2c,'\x01',0);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_450046d9(local_44,'\x01',0);
      }
      (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_78);
LAB_4501a994:
      local_8 = 0xffffffff;
      SysFreeString(local_78);
    }
  }
  else if (local_84 == (BSTR)0x1) {
    FUN_4501ae7e((void *)((int)this + -0x10),param_1,(int *)local_80);
  }
  else if (local_84 == (BSTR)0x3) {
    local_80 = (BSTR)0x0;
    local_8 = 6;
    (**(code **)(*(int *)*param_1 + 0xcc))((int *)*param_1,&local_80);
    (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_80);
    *(undefined1 *)((int)this + -8) = 1;
    iVar4 = *(int *)(*(int *)((int)this + -0xc) + 4);
    if ((*(char *)(iVar4 + 0xf0 + (int)this) == '\0') &&
       (bVar3 = FUN_450023b0((void *)((int)this + iVar4 + 0xd4),L"Capi"), bVar3)) {
      local_78 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,7);
      piVar8 = *(int **)(*(int *)(*(int *)((int)this + -0xc) + 4) + 0x54 + (int)this);
      (**(code **)(*piVar8 + 0x98))(piVar8,&local_78);
      FUN_4500e3e3(param_1,&local_78);
      SysFreeString(local_78);
    }
    local_8 = 0xffffffff;
    SysFreeString(local_80);
  }
  else if (local_84 == (BSTR)0x5) {
    FUN_4501aa65(param_1);
  }
  else if (local_84 == (BSTR)0x7) {
    if (local_79 == '\0') {
      FUN_4501c0b8((void *)((int)this + -0x10),param_1);
    }
  }
  else if ((local_84 == (BSTR)0x8) &&
          (iVar4 = *(int *)(*(int *)((int)this + -0xc) + 4), *(int *)(iVar4 + 0xc4 + (int)this) != 0
          )) {
    local_78 = (BSTR)0x0;
    piVar8 = *(int **)(iVar4 + 0xc4 + (int)this);
    local_8 = 0;
    iVar4 = (**(code **)(*piVar8 + 0x38))(piVar8,&local_78);
    if (iVar4 < 0) {
      SysFreeString(local_78);
      goto LAB_4501aa4d;
    }
    UVar5 = SysStringLen(local_78);
    if (UVar5 != 0) {
      (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_78);
      (**(code **)(*(int *)*param_1 + 0x5c))((int *)*param_1,local_78);
      (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,0);
      (**(code **)(*(int *)*param_1 + 0x44))((int *)*param_1,0);
    }
    goto LAB_4501a994;
  }
  bVar3 = FUN_4501b8d1(param_1);
  if (bVar3) {
    FUN_4501b5ab((int *)*param_1);
  }
  bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                       L"Print Preview");
  if (((bVar3) ||
      (bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                            L"JobSelection"), bVar3)) ||
     (bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0xd4),
                           L"Capi"), bVar3)) {
    CComQIPtr<>(&local_78,(undefined4 *)*param_1);
    local_8 = 8;
    if (local_78 != (BSTR)0x0) {
      FUN_45019d5f((void *)((int)this + -0x10),(int *)&local_78);
      FUN_45019ea0((int *)&local_78);
    }
    local_8 = 0xffffffff;
    if (local_78 != (BSTR)0x0) {
      (**(code **)(*(int *)local_78 + 8))(local_78);
    }
  }
LAB_4501aa4d:
  FUN_45022eb8();
  return;
}


