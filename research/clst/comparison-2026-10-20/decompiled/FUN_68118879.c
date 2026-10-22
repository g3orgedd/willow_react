// CiffMgr.dll entry=68118879

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG FUN_68118879(IUnknown *param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  IUnknown *pIVar1;
  int *piVar2;
  undefined4 *puVar3;
  ULONG UVar4;
  int iVar5;
  _union_2683 local_30;
  _union_2683 local_20;
  uint local_8;
  undefined4 uStack_4;
  
  puVar3 = param_3;
  piVar2 = param_2;
  uStack_4 = 0x20;
  local_8 = 0x68118885;
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  FUN_68132710((uint *)&local_30,0,0x10);
  VariantInit((VARIANTARG *)&local_30.n2);
  local_8 = 0;
  UVar4 = (**(code **)(param_1->lpVtbl->QueryInterface + 100))(param_1->lpVtbl,&local_30);
  if (-1 < (int)UVar4) {
    if (local_30.n2.vt == 9) {
      param_2 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      UVar4 = (*(code *)**(undefined4 **)local_30._8_4_)(local_30._8_4_,&DAT_681487b8,&param_2);
      if ((-1 < (int)UVar4) && (param_2 != (int *)0x0)) {
        UVar4 = (**(code **)(*param_2 + 0x1c))(param_2,piVar2);
      }
      local_8 = local_8 & 0xffffff00;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    if ((-1 < (int)UVar4) &&
       (UVar4 = (**(code **)(param_1->lpVtbl->QueryInterface + 0x1c))(param_1->lpVtbl,puVar3),
       pIVar1 = param_1, -1 < (int)UVar4)) {
      param_2 = (int *)0x0;
      UVar4 = (**(code **)(param_1->lpVtbl->QueryInterface + 0x1c))(param_1->lpVtbl,&param_2);
      if ((-1 < (int)UVar4) && (iVar5 = 0, 0 < (int)param_2)) {
        do {
          FUN_68132710((uint *)&local_20,0,0x10);
          VariantInit((VARIANTARG *)&local_20.n2);
          iVar5 = iVar5 + 1;
          local_8._0_1_ = 2;
          UVar4 = (**(code **)(pIVar1->lpVtbl->QueryInterface + 0x24))
                            (pIVar1->lpVtbl,iVar5,&local_20);
          if ((-1 < (int)UVar4) && ((local_20.n2.vt == 0xd || (local_20.n2.vt == 9)))) {
            param_1 = (IUnknown *)0x0;
            local_8._0_1_ = 3;
            if (((IUnknown *)local_20._8_4_ != (IUnknown *)0x0) &&
               ((ATL::AtlComQIPtrAssign(&param_1,(IUnknown *)local_20._8_4_,(_GUID *)&DAT_681482a0),
                param_1 != (IUnknown *)0x0 &&
                (UVar4 = (*param_1->lpVtbl[2].AddRef)(param_1), -1 < (int)UVar4)))) {
              *param_4 = *param_4 + (int)param_3;
            }
            local_8._0_1_ = 2;
            if (param_1 != (IUnknown *)0x0) {
              (*param_1->lpVtbl->Release)(param_1);
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          VariantClear((VARIANTARG *)&local_20.n2);
        } while (iVar5 < (int)param_2);
      }
    }
  }
  VariantClear((VARIANTARG *)&local_30.n2);
  return UVar4;
}


