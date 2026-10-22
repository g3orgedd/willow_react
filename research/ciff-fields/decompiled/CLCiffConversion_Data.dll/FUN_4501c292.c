// Source: CLCiffConversion_Data.dll @ 4501c292; FUN_4501c292

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4501c292(void *this,undefined4 *param_1)

{
  int iVar1;
  BSTR pOVar2;
  double *pdVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int local_8c [4];
  VARIANTARG local_7c;
  double local_6c;
  int local_64;
  int *local_60;
  int local_5c;
  double local_58;
  undefined8 local_50;
  int local_48;
  int *local_44;
  undefined8 local_40;
  BSTR local_38;
  undefined1 local_31;
  BSTR local_30;
  undefined8 local_2c [4];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_8 = 0x4501c29e;
  FUN_4501b7ce(param_1,&local_60,(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x38 + (int)this));
  local_8 = 0;
  if (local_60 != (int *)0x0) {
    FUN_45001f8d((uint *)&local_7c);
    local_8._0_1_ = 1;
    piVar6 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x38 + (int)this);
    (**(code **)(*piVar6 + 100))(piVar6,&local_7c);
    CComQIPtr<>(&local_44,(undefined4 *)local_7c.n1._8_4_);
    local_50 = DAT_4503d998;
    local_8 = CONCAT31(local_8._1_3_,2);
    (**(code **)(*local_60 + 0x4c))(local_60,&local_5c);
    if (local_5c == 4) {
      FUN_4501d16d(&local_50,0);
    }
    else {
      FUN_450040a4(&local_58);
      iVar1 = FUN_45003392();
      if (iVar1 != 0) {
        piVar7 = local_60;
        (**(code **)(*local_60 + 4))(local_60);
        piVar6 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x38 + (int)this);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 4))(piVar6);
        }
        pOVar2 = FUN_4501be66((BSTR)&local_6c,piVar6,piVar7);
        local_40._4_4_ = *(BSTR *)(pOVar2 + 2);
        FUN_4501df58(local_8c,0,0,0,0,0,*(int *)pOVar2);
        pdVar3 = FUN_4501d1ec((double *)&local_40,&local_58,local_8c);
        local_58 = *pdVar3;
      }
      puVar4 = (undefined8 *)FUN_4501cce9(&local_31,&local_6c,this,local_44,local_60,&local_58);
      local_50 = *puVar4;
    }
    FUN_4500fe88(param_1,&local_38);
    local_8._0_1_ = 3;
    puVar5 = FUN_4501b8f3(param_1,(undefined4 *)((int)&local_40 + 4));
    local_8._0_1_ = 4;
    basic_string<>(local_2c,(wchar_t *)*puVar5);
    SysFreeString(local_40._4_4_);
    local_30 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_4501da6f(&local_50,(int *)&local_38,(int *)&local_30,local_2c,0);
    (**(code **)(*local_60 + 0x24))(local_60,&local_64);
    (**(code **)(*local_60 + 0xc4))(local_60,&local_48);
    if ((local_48 == 0) ||
       ((*(char *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x100 + (int)this) == '\0' &&
        (local_64 != 0)))) {
      (**(code **)(*local_60 + 200))(local_60,0);
      FUN_4500e3e3(param_1,&local_30);
      *(undefined1 *)((int)this + 8) = 1;
    }
    (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_30);
    SysFreeString(local_30);
    FUN_450046d9(local_2c,'\x01',0);
    SysFreeString(local_38);
    local_8._0_1_ = 1;
    if (local_44 != (int *)0x0) {
      (**(code **)(*local_44 + 8))(local_44);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    VariantClear(&local_7c);
  }
  piVar6 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 100 + (int)this);
  (**(code **)(*piVar6 + 0x94))(piVar6,0);
  local_8 = 0xffffffff;
  if (local_60 != (int *)0x0) {
    (**(code **)(*local_60 + 8))(local_60);
  }
  FUN_45022eb8();
  return;
}


