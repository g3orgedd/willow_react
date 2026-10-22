// Source: CiffHelper.dll @ 4081ce86; FUN_4081ce86

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_4081ce86(undefined4 *param_1,void *param_2,wchar_t *param_3)

{
  IUnknown *This;
  char cVar1;
  undefined1 uVar2;
  IUnknown *This_00;
  VARIANTARG local_34;
  int local_20;
  int local_1c;
  IUnknown *local_18;
  IUnknown *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_18 = (IUnknown *)0x0;
  This_00 = (IUnknown *)0x0;
  local_14[0] = (IUnknown *)0x0;
  local_20 = 0;
  uVar2 = 1;
  local_8 = 1;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_20);
  local_1c = 0;
  if (0 < local_20) {
    do {
      FUN_40802e76((uint *)&local_34);
      local_1c = local_1c + 1;
      local_8 = CONCAT31(local_8._1_3_,2);
      (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,local_1c,&local_34);
      if (local_18 != (IUnknown *)local_34.n1._8_4_) {
        ATL::AtlComQIPtrAssign(&local_18,(IUnknown *)local_34.n1._8_4_,(_GUID *)&DAT_4084a938);
      }
      local_14[0] = local_18;
      if (local_18 != (IUnknown *)0x0) {
        (*local_18->lpVtbl->AddRef)(local_18);
      }
      cVar1 = FUN_4081d0dc(local_14,param_3);
      This = local_14[0];
      if (cVar1 != '\0') {
        FUN_4080888b(param_2,(int *)local_14);
        VariantClear(&local_34);
        This_00 = local_14[0];
        goto LAB_4081cf5f;
      }
      This_00 = local_14[0];
      if (local_14[0] != (IUnknown *)0x0) {
        This_00 = (IUnknown *)0x0;
        local_14[0] = (IUnknown *)0x0;
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
      }
      VariantClear(&local_34);
      VariantClear(&local_34);
    } while (local_1c < local_20);
  }
  uVar2 = 0;
LAB_4081cf5f:
  local_8 = local_8 & 0xffffff00;
  if (This_00 != (IUnknown *)0x0) {
    (*This_00->lpVtbl->Release)(This_00);
  }
  local_8 = 0xffffffff;
  if (local_18 != (IUnknown *)0x0) {
    (*local_18->lpVtbl->Release)(local_18);
  }
  return uVar2;
}


