// Source: CLCiffConversion_Layout.dll @ 4540611b; FUN_4540611b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __cdecl FUN_4540611b(IUnknown *param_1,BSTR param_2)

{
  int *piVar1;
  uchar uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  void **in_stack_ffffffb4;
  _union_2683 local_3c;
  _union_2683 local_2c;
  int *local_1c;
  int *local_18;
  IID local_14;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_14.Data4[4] = '\0';
  local_14.Data4[5] = '\0';
  local_14.Data4[6] = '\0';
  local_14.Data4[7] = '\0';
  if (param_1->lpVtbl == (IUnknownVtbl *)0x0) {
    uVar5 = 0x80004003;
  }
  else {
    local_14.Data1 = 0;
    local_18 = (int *)0x0;
    iVar4 = FUN_4541a358(param_1,(int *)&local_18);
    FUN_45429f70((uint *)&local_3c,0,0x10);
    VariantInit((VARIANTARG *)&local_3c.n2);
    piVar1 = local_18;
    local_14.Data4[4] = '\x03';
    if (-1 < iVar4) {
      if (local_18 != (int *)0x0) {
        iVar4 = (**(code **)(*local_18 + 0x474))(local_18,&local_3c);
      }
      if ((-1 < iVar4) && (local_3c.n2.vt != 0)) {
        CComQIPtr<>(&local_1c,(undefined4 *)local_3c._8_4_);
        FUN_45429f70((uint *)&local_2c,0,0x10);
        VariantInit((VARIANTARG *)&local_2c.n2);
        local_14.Data4[4] = '\x05';
        uVar2 = local_14.Data4[4];
        local_14.Data4[4] = '\x05';
        if (local_1c != (int *)0x0) {
          iVar4 = (**(code **)(*local_1c + 0x30))(local_1c,param_2,&local_2c);
          param_1 = (IUnknown *)0x0;
          local_14.Data4[4] = '\x06';
          if (((-1 < iVar4) && (local_2c.n2.vt != 0)) &&
             ((IUnknown *)local_2c._8_4_ != (IUnknown *)0x0)) {
            ATL::AtlComQIPtrAssign(&param_1,(IUnknown *)local_2c._8_4_,(_GUID *)&DAT_45447760);
            if (param_1 != (IUnknown *)0x0) {
              iVar4 = (*param_1->lpVtbl[0xd].QueryInterface)(param_1,&local_14,in_stack_ffffffb4);
            }
          }
          local_14.Data4[4] = '\x05';
          uVar2 = local_14.Data4[4];
          if (param_1 != (IUnknown *)0x0) {
            (*param_1->lpVtbl->Release)(param_1);
            uVar2 = local_14.Data4[4];
          }
        }
        local_14.Data4[4] = uVar2;
        VariantClear((VARIANTARG *)&local_2c.n2);
        local_14.Data4[4] = '\x03';
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
    }
    local_14.Data4[4] = '\x02';
    VariantClear((VARIANTARG *)&local_3c.n2);
    if (iVar4 < 0) {
      uVar5 = 0x80004005;
    }
    else {
      bVar3 = FUN_45402d4b(&local_14,L"ZFBF");
      uVar5 = (uint)!bVar3;
    }
    local_14.Data4[4] = '\x01';
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    SysFreeString((BSTR)local_14.Data1);
  }
  SysFreeString(param_2);
  return uVar5;
}


