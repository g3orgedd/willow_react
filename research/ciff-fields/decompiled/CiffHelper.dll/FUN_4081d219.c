// Source: CiffHelper.dll @ 4081d219; FUN_4081d219

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_4081d219(undefined4 *param_1,void *param_2,wchar_t *param_3)

{
  char cVar1;
  undefined1 uVar2;
  IUnknown *pIVar3;
  IUnknown *This;
  VARIANTARG local_34;
  int local_20;
  int local_1c;
  IUnknown *local_18;
  IUnknown *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_14[0] = (IUnknown *)0x0;
  pIVar3 = (IUnknown *)0x0;
  local_18 = (IUnknown *)0x0;
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
      if (local_14[0] != (IUnknown *)local_34.n1._8_4_) {
        ATL::AtlComQIPtrAssign(local_14,(IUnknown *)local_34.n1._8_4_,(_GUID *)&DAT_4084a928);
      }
      This = local_14[0];
      local_18 = local_14[0];
      if (local_14[0] != (IUnknown *)0x0) {
        (*local_14[0]->lpVtbl->AddRef)(local_14[0]);
      }
      cVar1 = FUN_4081ce86(&local_18,param_2,param_3);
      if (cVar1 != '\0') {
        VariantClear(&local_34);
        goto LAB_4081d2f2;
      }
      pIVar3 = This;
      if (This != (IUnknown *)0x0) {
        pIVar3 = (IUnknown *)0x0;
        local_18 = (IUnknown *)0x0;
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
      }
      VariantClear(&local_34);
      VariantClear(&local_34);
    } while (local_1c < local_20);
  }
  uVar2 = 0;
  This = pIVar3;
LAB_4081d2f2:
  local_8 = local_8 & 0xffffff00;
  if (This != (IUnknown *)0x0) {
    (*This->lpVtbl->Release)(This);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (IUnknown *)0x0) {
    (*local_14[0]->lpVtbl->Release)(local_14[0]);
  }
  return uVar2;
}


