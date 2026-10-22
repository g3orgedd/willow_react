// Source: CiffMgr.dll @ 68118a19; FUN_68118a19

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG FUN_68118a19(undefined4 *param_1,BSTR param_2,IUnknown *param_3)

{
  IUnknown *this;
  ULONG UVar1;
  int iVar2;
  UINT UVar3;
  int iVar4;
  int iVar5;
  _union_2683 local_44;
  _union_2683 local_34;
  int local_24;
  int local_20;
  int local_1c;
  BSTR local_18;
  IUnknown *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  this = param_3;
  uStack_4 = 0x34;
  local_8 = 0x68118a25;
  SysFreeString((BSTR)param_3->lpVtbl);
  this->lpVtbl = (IUnknownVtbl *)0x0;
  local_20 = 0;
  UVar1 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_20);
  if ((-1 < (int)UVar1) && (iVar4 = 0, 0 < local_20)) {
    do {
      if (param_2 == (BSTR)0x0) break;
      FUN_68132710((uint *)&local_44,0,0x10);
      VariantInit((VARIANTARG *)&local_44.n2);
      local_8 = 0;
      iVar4 = iVar4 + 1;
      local_24 = iVar4;
      UVar1 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar4,&local_44);
      if ((-1 < (int)UVar1) && ((local_44.n2.vt == 0xd || (local_44.n2.vt == 9)))) {
        param_3 = (IUnknown *)0x0;
        local_8._0_1_ = 1;
        if (((IUnknown *)local_44._8_4_ != (IUnknown *)0x0) &&
           (ATL::AtlComQIPtrAssign(&param_3,(IUnknown *)local_44._8_4_,(_GUID *)&DAT_681482a0),
           param_3 != (IUnknown *)0x0)) {
          local_1c = 0;
          UVar1 = (*param_3->lpVtbl[2].AddRef)(param_3);
          if ((-1 < (int)UVar1) && (iVar5 = 0, iVar2 = local_1c, iVar4 = local_24, 0 < local_1c)) {
            do {
              iVar4 = local_24;
              if (param_2 == (BSTR)0x0) break;
              if (((uint)param_2 & 1) != 0) {
                FUN_68132710((uint *)&local_34,0,0x10);
                VariantInit((VARIANTARG *)&local_34.n2);
                local_8._0_1_ = 2;
                UVar1 = (*param_3->lpVtbl[3].QueryInterface)
                                  (param_3,(IID *)(iVar5 + 1),(void **)&local_34);
                if ((-1 < (int)UVar1) && ((local_34.n2.vt == 0xd || (local_34.n2.vt == 9)))) {
                  local_14[0] = (IUnknown *)0x0;
                  if (((IUnknown *)local_34._8_4_ != (IUnknown *)0x0) &&
                     (ATL::AtlComQIPtrAssign
                                (local_14,(IUnknown *)local_34._8_4_,(_GUID *)&DAT_6814a33c),
                     local_14[0] != (IUnknown *)0x0)) {
                    local_18 = (BSTR)0x0;
                    local_8._0_1_ = 4;
                    UVar1 = (*local_14[0]->lpVtbl[0xc].Release)(local_14[0]);
                    if (-1 < (int)UVar1) {
                      FUN_6811823c(this,local_18);
                    }
                    SysFreeString(local_18);
                  }
                  local_8._0_1_ = 2;
                  if (local_14[0] != (IUnknown *)0x0) {
                    (*local_14[0]->lpVtbl->Release)(local_14[0]);
                  }
                }
                VariantClear((VARIANTARG *)&local_34.n2);
                iVar2 = local_1c;
              }
              iVar5 = iVar5 + 1;
              param_2 = (BSTR)((uint)param_2 >> 1);
              iVar4 = local_24;
            } while (iVar5 < iVar2);
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (param_3 != (IUnknown *)0x0) {
          (*param_3->lpVtbl->Release)(param_3);
        }
      }
      local_8 = 0xffffffff;
      VariantClear((VARIANTARG *)&local_44.n2);
    } while (iVar4 < local_20);
  }
  UVar3 = SysStringLen((BSTR)this->lpVtbl);
  if (0x14 < UVar3) {
    param_2 = SysAllocStringLen((OLECHAR *)this->lpVtbl,0x14);
    if (param_2 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_681024d6(-0x7ff8fff2);
    }
    FUN_681181da(this,(int *)&param_2);
    SysFreeString(param_2);
  }
  return UVar1;
}


