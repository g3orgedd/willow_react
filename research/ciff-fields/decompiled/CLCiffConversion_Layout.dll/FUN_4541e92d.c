// Source: CLCiffConversion_Layout.dll @ 4541e92d; FUN_4541e92d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uchar __thiscall FUN_4541e92d(void *this,BSTR param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  void **in_stack_ffffffa8;
  _union_2683 local_48;
  _union_2683 local_38;
  int *local_28;
  int *local_24;
  int *local_20;
  undefined1 local_1c [4];
  IUnknown *local_18;
  uchar local_11;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_1c = (undefined1  [4])0x0;
  local_8 = 1;
  uStack_7 = 0;
  piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
  local_28 = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar3 = (int *)0x0;
  local_20 = (int *)0x0;
  local_8 = 3;
  uVar2 = local_8;
  local_8 = 3;
  if (piVar1 != (int *)0x0) {
    FUN_4541a358(&local_28,(int *)&local_20);
    FUN_45429f70((uint *)&local_48,0,0x10);
    VariantInit((VARIANTARG *)&local_48.n2);
    piVar3 = local_20;
    local_8 = 4;
    (**(code **)(*local_20 + 0x474))(local_20,&local_48);
    if (local_48.n2.vt != 0) {
      CComQIPtr<>(&local_24,(undefined4 *)local_48._8_4_);
      FUN_45429f70((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      local_8 = 6;
      uVar2 = local_8;
      local_8 = 6;
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 0x30))(local_24,param_1,&local_38);
        local_18 = (IUnknown *)0x0;
        local_8 = 7;
        if ((local_38.n2.vt != 0) && ((IUnknown *)local_38._8_4_ != (IUnknown *)0x0)) {
          ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_38._8_4_,(_GUID *)&DAT_45447760);
          if (local_18 != (IUnknown *)0x0) {
            (*local_18->lpVtbl[0xd].QueryInterface)(local_18,(IID *)local_1c,in_stack_ffffffa8);
          }
        }
        local_8 = 6;
        uVar2 = local_8;
        if (local_18 != (IUnknown *)0x0) {
          (*local_18->lpVtbl->Release)(local_18);
          uVar2 = local_8;
        }
      }
      local_8 = uVar2;
      VariantClear((VARIANTARG *)&local_38.n2);
      local_8 = 4;
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 8))(local_24);
      }
    }
    local_8 = 3;
    VariantClear((VARIANTARG *)&local_48.n2);
    uVar2 = local_8;
  }
  local_8 = uVar2;
  local_11 = FUN_45402d4b(local_1c,L"ZFBF");
  local_8 = 2;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  _local_8 = CONCAT31(uStack_7,1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString((BSTR)local_1c);
  SysFreeString(param_1);
  return local_11;
}


