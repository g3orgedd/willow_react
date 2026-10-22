// Source: CLCSBarcodeField.dll @ 4144c457; FUN_4144c457

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_4144c457(void **param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  ULONG UVar2;
  int iVar3;
  void **ppvObject;
  VARIANTARG local_44;
  VARIANTARG local_34;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  IUnknown *local_18;
  IUnknown *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0;
  if (((param_1 == (void **)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar3 = 0;
    FUN_41460bf0((uint *)&local_44,0,0x10);
    VariantInit(&local_44);
    local_8._0_1_ = 3;
    ppvObject = param_1;
    iVar1 = (**(code **)((int)*param_1 + 0x7c))(param_1,&local_44);
    local_14[0] = (IUnknown *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((-1 < iVar1) && ((IUnknown *)local_44.n1._8_4_ != (IUnknown *)0x0)) {
      ATL::AtlComQIPtrAssign(local_14,(IUnknown *)local_44.n1._8_4_,(_GUID *)&DAT_41484af8);
    }
    local_1c = (undefined1  [4])0x0;
    if ((-1 < iVar1) && (local_14[0] != (IUnknown *)0x0)) {
      UVar2 = (*local_14[0]->lpVtbl[3].QueryInterface)(local_14[0],(IID *)local_1c,ppvObject);
      iVar1 = 0;
      if (0 < (int)local_1c) {
        do {
          if ((int)UVar2 < 0) break;
          FUN_41460bf0((uint *)&local_34,0,0x10);
          VariantInit(&local_34);
          iVar1 = iVar1 + 1;
          local_8._0_1_ = 5;
          UVar2 = (*local_14[0]->lpVtbl[2].Release)(local_14[0]);
          local_18 = (IUnknown *)0x0;
          local_8 = CONCAT31(local_8._1_3_,6);
          if ((-1 < (int)UVar2) && ((IUnknown *)local_34.n1._8_4_ != (IUnknown *)0x0)) {
            ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_34.n1._8_4_,(_GUID *)&DAT_41484b08);
          }
          local_20 = 0;
          if (-1 < (int)UVar2) {
            if (local_18 != (IUnknown *)0x0) {
              UVar2 = (*local_18->lpVtbl[3].Release)(local_18);
            }
            if ((-1 < (int)UVar2) && (iVar3 < local_20)) {
              iVar3 = local_20;
            }
          }
          local_8._0_1_ = 5;
          if (local_18 != (IUnknown *)0x0) {
            (*local_18->lpVtbl->Release)(local_18);
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          VariantClear(&local_34);
        } while (iVar1 < (int)local_1c);
      }
    }
    local_24 = 0;
    iVar1 = (**(code **)(*param_2 + 0x54))(param_2,&local_24);
    if ((iVar1 < 0) || (local_24 != 0)) {
      *param_4 = iVar3;
    }
    else {
      local_18 = (IUnknown *)0x0;
      iVar1 = (**(code **)(*param_3 + 0x34))(param_3,&local_18);
      local_18 = (IUnknown *)((float)local_18 * _DAT_4148100c);
      iVar3 = FUN_414092db((float)(iVar3 * 100) / (float)local_18);
      *param_4 = iVar3;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_14[0] != (IUnknown *)0x0) {
      (*local_14[0]->lpVtbl->Release)(local_14[0]);
    }
    VariantClear(&local_44);
  }
  local_8._0_1_ = 1;
  if (param_1 != (void **)0x0) {
    (**(code **)((int)*param_1 + 8))(param_1);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return iVar1;
}


