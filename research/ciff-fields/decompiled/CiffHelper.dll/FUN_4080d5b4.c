// Source: CiffHelper.dll @ 4080d5b4; FUN_4080d5b4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4080d5b4(void *this,int *param_1,int *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  BSTR pOVar3;
  int *piVar4;
  double *pdVar5;
  undefined8 *puVar6;
  BSTR extraout_ECX;
  int *piVar7;
  VARIANTARG local_7c;
  OLECHAR local_6c [2];
  void *local_68;
  double local_64;
  int local_5c;
  undefined8 local_58;
  double local_50;
  int *local_48;
  int *local_44;
  wchar_t *local_40;
  BSTR local_3c;
  BSTR local_38;
  int *local_34;
  BSTR local_30;
  undefined1 local_2c [8];
  undefined1 local_24 [28];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0xc0;
  uStack_7 = 0x4080d5;
  local_48 = param_1;
  local_68 = this;
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) goto LAB_4080d7f8;
  FUN_40805bf7(&local_64);
  iVar2 = (**(code **)(*param_2 + 0x28))();
  if (iVar2 < 0) goto LAB_4080d7f8;
  if (local_5c == 4) {
    local_30 = (BSTR)0x0;
    local_8 = 0;
    uStack_7 = 0;
    iVar2 = (**(code **)(*param_2 + 0xb4))();
    if (-1 < iVar2) {
      FUN_40802e76((uint *)&local_7c);
      local_8 = 1;
      iVar2 = (**(code **)(*local_48 + 100))();
      if (-1 < iVar2) {
        CComQIPtr<>(&local_44,(undefined4 *)local_7c.n1._8_4_);
        local_8 = 2;
        pOVar3 = (BSTR)&stack0xffffff70;
        local_58 = (double)CONCAT44(&stack0xffffff70,(undefined4)local_58);
        piVar4 = local_44;
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 4))();
          pOVar3 = extraout_ECX;
        }
        local_8 = 3;
        FUN_40803baf(&stack0xffffff6c,(int *)&local_30);
        local_8 = 2;
        FUN_4081bb85(&local_34,pOVar3,piVar4);
        local_8 = 4;
        if (local_34 != (int *)0x0) {
          FUN_40805bf7(&local_58);
          bVar1 = FUN_4081d4ef();
          if (bVar1) {
            piVar4 = local_34;
            if (local_34 != (int *)0x0) {
              (**(code **)(*local_34 + 4))();
            }
            piVar7 = local_48;
            (**(code **)(*local_48 + 4))(local_48);
            pOVar3 = FUN_4080e73f(local_6c,piVar7,piVar4);
            piVar4 = FUN_4080e725(local_24,*(int *)pOVar3);
            pdVar5 = FUN_408294b5(&local_50,(double *)&local_58,piVar4);
            local_58 = *pdVar5;
          }
          pdVar5 = FUN_40828c80(&local_50,local_44,local_34,(double *)&local_58);
          local_64 = *pdVar5;
        }
        local_8 = 2;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))();
        }
        _local_8 = CONCAT31(uStack_7,1);
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 8))();
        }
        VariantClear(&local_7c);
        SysFreeString(local_30);
        goto LAB_4080d763;
      }
      VariantClear(&local_7c);
    }
    SysFreeString(local_30);
  }
  else {
LAB_4080d763:
    local_3c = (BSTR)0x0;
    local_8 = 5;
    uStack_7 = 0;
    iVar2 = (**(code **)(*param_2 + 0x58))();
    if (-1 < iVar2) {
      local_40 = (wchar_t *)0x0;
      local_8 = 6;
      iVar2 = (**(code **)(*param_2 + 0x80))();
      if (-1 < iVar2) {
        local_38 = (BSTR)0x0;
        local_8 = 7;
        puVar6 = (undefined8 *)basic_string<>(local_2c,local_40);
        local_8 = 8;
        FUN_4082991d(&local_64,(int *)&local_3c,(int *)&local_38,puVar6,param_3);
        local_8 = 7;
        FUN_4080653d(local_2c,'\x01',0);
        (**(code **)(*param_2 + 100))();
        SysFreeString(local_38);
      }
      SysFreeString(local_40);
    }
    SysFreeString(local_3c);
  }
LAB_4080d7f8:
  FUN_4082d4c6();
  return;
}


