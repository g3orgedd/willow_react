// Source: CLARiSOFT.exe @ 00eb1fd0; FUN_00eb1fd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00eb1fd0(void *this,BSTR param_1,BSTR param_2)

{
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  _union_2683 local_2c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  FUN_00e384b8((int *)(*(int *)((int)this + 0x10) + 4));
  pOVar5 = param_2;
  if (param_2 != (BSTR)0x0) {
    (**(code **)(*(int *)param_2 + 4))(param_2);
  }
  pOVar4 = param_1;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 4))(param_1);
  }
  FUN_00eb2485(this,(int *)pOVar4,(int *)pOVar5);
  if ((param_2 != (BSTR)0x0) && (UVar2 = SysStringLen(*(BSTR *)((int)this + 0x20)), UVar2 != 0)) {
    local_18 = 0;
    iVar3 = (**(code **)(*(int *)param_2 + 0x490))(param_2);
    if ((-1 < iVar3) && (local_18 == 0)) {
      FUN_00e03b51((uint *)&local_2c);
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar3 = (**(code **)(*(int *)param_2 + 0x4c0))(param_2,*(undefined4 *)((int)this + 0x20));
      if ((((-1 < iVar3) && (local_2c.n2.vt == 9)) &&
          ((undefined4 *)local_2c._8_4_ != (undefined4 *)0x0)) &&
         ((CComQIPtr<>(local_14,(undefined4 *)local_2c._8_4_), local_14[0] != (int *)0x0 &&
          (FUN_00e11de5(&param_2,(int *)local_14), local_14[0] != (int *)0x0)))) {
        (**(code **)(*local_14[0] + 8))();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      VariantClear((VARIANTARG *)&local_2c.n2);
    }
  }
  pOVar5 = param_2;
  if (param_2 != (BSTR)0x0) {
    (**(code **)(*(int *)param_2 + 4))(param_2);
  }
  pOVar4 = param_1;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 4))(param_1);
  }
  FUN_00eb1c80(this,pOVar4,pOVar5);
  uVar1 = *(undefined4 *)((int)this + 0x10);
  local_8 = local_8 & 0xffffff00;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_2 != (BSTR)0x0) {
    (**(code **)(*(int *)param_2 + 8))();
  }
  return uVar1;
}


