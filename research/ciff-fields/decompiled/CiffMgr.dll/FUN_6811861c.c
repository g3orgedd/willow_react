// Source: CiffMgr.dll @ 6811861c; FUN_6811861c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG __thiscall FUN_6811861c(void *this,BSTR param_1)

{
  BSTR pOVar1;
  int iVar2;
  IUnknownVtbl *pIVar3;
  IUnknownVtbl *pIVar4;
  IUnknown _Dst;
  IUnknown _Dst_00;
  IUnknownVtbl *local_3c;
  IUnknownVtbl *local_38;
  IUnknownVtbl *local_34;
  BSTR local_30;
  IUnknownVtbl *local_2c;
  BSTR local_28;
  IUnknown local_24;
  IUnknownVtbl *local_20;
  IUnknown local_1c;
  IUnknownVtbl *local_18;
  ULONG local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x68118628;
  pIVar3 = *(IUnknownVtbl **)param_1;
  if (pIVar3 == (IUnknownVtbl *)0x0) {
    local_14 = 0x80004003;
  }
  else {
    local_2c = pIVar3;
    local_28 = this;
    local_24.lpVtbl = pIVar3;
    (**(code **)(pIVar3->QueryInterface + 4))(pIVar3);
    local_8 = 0;
    local_14 = FUN_68118879(&local_24,(int *)&local_3c,&local_38,(int *)&local_20);
    if (-1 < (int)local_14) {
      local_30 = (BSTR)0x0;
      local_18 = (IUnknownVtbl *)0x0;
      if (0 < (int)local_20) {
        pIVar3 = (IUnknownVtbl *)0x3;
        if ((int)local_20 < 3) {
          pIVar3 = local_20;
        }
        iVar2 = FUN_68118e73((int)pIVar3);
        pIVar3 = (IUnknownVtbl *)(iVar2 + 1);
        local_34 = pIVar3;
        if (0 < (int)pIVar3) {
          local_1c.lpVtbl = (IUnknownVtbl *)0x20;
          if ((int)local_20 < 0x20) {
            local_1c.lpVtbl = local_20;
          }
          do {
            iVar2 = FUN_68118e73((int)local_1c.lpVtbl);
            local_18 = (IUnknownVtbl *)((uint)local_18 | 1 << ((byte)iVar2 & 0x1f));
            pIVar3 = (IUnknownVtbl *)((int)&pIVar3[-1].Release + 3);
          } while (pIVar3 != (IUnknownVtbl *)0x0);
        }
        local_1c.lpVtbl = (IUnknownVtbl *)0x0;
        local_8 = CONCAT31(local_8._1_3_,2);
        local_14 = FUN_68118a19(&local_24,(BSTR)local_18,&local_1c);
        if (-1 < (int)local_14) {
          (**(code **)(*(int *)((int)this + 0x10) + 8))
                    ((int *)((int)this + 0x10),local_1c.lpVtbl,*(undefined4 *)((int)this + 0xaf4),
                     *(undefined4 *)((int)this + 0xafc),0,&local_30);
        }
        SysFreeString((BSTR)local_1c.lpVtbl);
      }
      local_34 = (IUnknownVtbl *)0x0;
      local_1c.lpVtbl = (IUnknownVtbl *)SysAllocStringLen((OLECHAR *)0x0,8);
      _Dst.lpVtbl = (IUnknownVtbl *)0x0;
      if (local_1c.lpVtbl != (IUnknownVtbl *)0x0) {
        SysFreeString((BSTR)0x0);
        local_34 = local_1c.lpVtbl;
        _Dst.lpVtbl = local_1c.lpVtbl;
      }
      _swprintf_s((wchar_t *)_Dst.lpVtbl,9,L"%08X",local_18);
      param_1 = (BSTR)0x0;
      local_1c.lpVtbl = (IUnknownVtbl *)0x0;
      local_8 = CONCAT31(local_8._1_3_,5);
      local_18 = (IUnknownVtbl *)SysAllocStringLen((OLECHAR *)0x0,6);
      _Dst_00.lpVtbl = (IUnknownVtbl *)0x0;
      if (local_18 != (IUnknownVtbl *)0x0) {
        SysFreeString((BSTR)0x0);
        local_1c.lpVtbl = local_18;
        _Dst_00.lpVtbl = local_18;
      }
      pIVar3 = (IUnknownVtbl *)0x63;
      pIVar4 = local_20;
      if (99 < (int)local_20) {
        pIVar4 = pIVar3;
      }
      if (99 < (int)local_38) {
        local_38 = pIVar3;
      }
      if (99 < (int)local_3c) {
        local_3c = pIVar3;
      }
      _swprintf_s((wchar_t *)_Dst_00.lpVtbl,7,L"%02ld%02ld%02ld",local_3c,local_38,pIVar4);
      (**(code **)(*(int *)(local_28 + 8) + 8))
                (local_28 + 8,_Dst.lpVtbl,_Dst_00.lpVtbl,*(undefined4 *)(local_28 + 0x57e),0,
                 &param_1);
      FUN_6811823c(&param_1,local_30);
      pIVar3 = local_2c;
      if ((char)local_28[6] != '\0') {
        local_20 = (IUnknownVtbl *)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        local_14 = FUN_681182fa(local_28,(int *)&local_24,&local_1c,&local_34,&param_1,&local_20);
        if (-1 < (int)local_14) {
          FUN_68118200(&param_1,(int *)&local_20);
        }
        SysFreeString((BSTR)local_20);
        _Dst_00.lpVtbl = local_1c.lpVtbl;
      }
      pOVar1 = local_28;
      if (-1 < (int)local_14) {
        local_28 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        (**(code **)(*(int *)(pOVar1 + 8) + 8))
                  (pOVar1 + 8,param_1,*(undefined4 *)(pOVar1 + 0x57c),
                   *(undefined4 *)(pOVar1 + 0x57e),0,&local_28);
        pIVar3 = local_2c;
        local_14 = (**(code **)(local_2c->QueryInterface + 0x7c))(local_2c,local_28);
        SysFreeString(local_28);
      }
      SysFreeString((BSTR)_Dst_00.lpVtbl);
      SysFreeString(param_1);
      SysFreeString((BSTR)_Dst.lpVtbl);
      SysFreeString(local_30);
    }
    local_8 = 0xffffffff;
    (**(code **)(pIVar3->QueryInterface + 8))(pIVar3);
  }
  return local_14;
}


