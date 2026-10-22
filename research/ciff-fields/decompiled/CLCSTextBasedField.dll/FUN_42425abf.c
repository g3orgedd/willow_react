// Source: CLCSTextBasedField.dll @ 42425abf; FUN_42425abf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall
FUN_42425abf(void *this,BSTR param_1,undefined4 param_2,undefined4 param_3,IUnknown *param_4)

{
  undefined1 uVar1;
  bool bVar2;
  IUnknown *This;
  void **in_stack_ffffffac;
  void **in_stack_ffffffb0;
  _union_2683 local_44;
  _union_2683 local_34;
  IUnknown *local_24;
  int *local_20;
  undefined1 local_1c [4];
  IUnknown *local_18;
  IUnknown *local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_1c = (undefined1  [4])0x0;
  local_14[0] = *(IUnknown **)((int)this + 0xe0);
  local_8 = 1;
  uStack_7 = 0;
  if (local_14[0] != (IUnknown *)0x0) {
    (*local_14[0]->lpVtbl->AddRef)(local_14[0]);
  }
  This = (IUnknown *)0x0;
  local_24 = (IUnknown *)0x0;
  local_8 = 3;
  if (local_14[0] == (IUnknown *)0x0) {
    if (param_4 == (IUnknown *)0x0) goto LAB_42425bee;
    ATL::AtlComQIPtrAssign(local_14,param_4,(_GUID *)&DAT_424956f8);
    if (local_14[0] == (IUnknown *)0x0) goto LAB_42425bee;
  }
  This = local_14[0];
  local_24 = local_14[0];
  if (local_14[0] != (IUnknown *)0x0) {
    (*local_14[0]->lpVtbl->AddRef)(local_14[0]);
  }
  FUN_42403802((uint *)&local_44);
  local_8 = 4;
  (*This->lpVtbl[0x5f].QueryInterface)(This,(IID *)&local_44.n2,in_stack_ffffffac);
  if (local_44.n2.vt != 0) {
    CComQIPtr<>(&local_20,(undefined4 *)local_44._8_4_);
    FUN_42403802((uint *)&local_34);
    local_8 = 6;
    uVar1 = local_8;
    local_8 = 6;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 0x30))(local_20,param_1,&local_34);
      local_18 = (IUnknown *)0x0;
      local_8 = 7;
      if ((local_34.n2.vt != 0) && ((IUnknown *)local_34._8_4_ != (IUnknown *)0x0)) {
        ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_34._8_4_,(_GUID *)&DAT_42495a7c);
        if (local_18 != (IUnknown *)0x0) {
          (*local_18->lpVtbl[0xd].QueryInterface)(local_18,(IID *)local_1c,in_stack_ffffffb0);
        }
      }
      local_8 = 6;
      uVar1 = local_8;
      if (local_18 != (IUnknown *)0x0) {
        (*local_18->lpVtbl->Release)(local_18);
        uVar1 = local_8;
      }
    }
    local_8 = uVar1;
    VariantClear((VARIANTARG *)&local_34.n2);
    local_8 = 4;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  local_8 = 3;
  VariantClear((VARIANTARG *)&local_44.n2);
LAB_42425bee:
  bVar2 = FUN_42403bfa(local_1c,L"ZFBF");
  local_8 = 2;
  if (This != (IUnknown *)0x0) {
    (*This->lpVtbl->Release)(This);
  }
  _local_8 = CONCAT31(uStack_7,1);
  if (local_14[0] != (IUnknown *)0x0) {
    (*local_14[0]->lpVtbl->Release)(local_14[0]);
  }
  SysFreeString((BSTR)local_1c);
  SysFreeString(param_1);
  return bVar2;
}


