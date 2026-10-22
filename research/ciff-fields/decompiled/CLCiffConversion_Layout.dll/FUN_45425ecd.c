// Source: CLCiffConversion_Layout.dll @ 45425ecd; FUN_45425ecd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_45425ecd(void *this,LCID param_1)

{
  ITypeInfoVtbl *pIVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  DWORD DVar5;
  size_t sVar6;
  long lVar7;
  wchar_t *pwVar8;
  HRESULT HVar9;
  ITypeInfoVtbl *pIVar10;
  wchar_t local_140 [8];
  LPCRITICAL_SECTION local_130;
  undefined1 local_12c;
  ITypeInfoVtbl *local_128;
  ITypeLib *local_124;
  int *local_120;
  ITypeInfoVtbl *local_11c;
  CHAR local_118 [272];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x120;
  local_8 = 0x45425edc;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_45426179;
  local_130 = (LPCRITICAL_SECTION)(DAT_4545fba8 + 0x10);
  local_8 = 0;
  EnterCriticalSection(local_130);
  local_12c = 1;
  if (*(int *)((int)this + 0xc) == 0) {
    local_124 = (ITypeLib *)0x0;
    iVar4 = _InlineIsEqualGUID(&DAT_4545fbac,*(int **)((int)this + 4));
    if (((iVar4 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      HVar9 = LoadRegTypeLib(*(GUID **)((int)this + 4),*(WORD *)((int)this + 8),
                             *(WORD *)((int)this + 10),param_1,&local_124);
LAB_4542605b:
      if (-1 < HVar9) {
        local_11c = (ITypeInfoVtbl *)0x0;
        local_8._0_1_ = 2;
        HVar9 = (*local_124->lpVtbl->GetTypeInfoOfGuid)
                          (local_124,*(GUID **)this,(ITypeInfo **)&local_11c);
        if (-1 < HVar9) {
          local_128 = local_11c;
          if (local_11c != (ITypeInfoVtbl *)0x0) {
            (**(code **)(local_11c->QueryInterface + 4))(local_11c);
          }
          local_120 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,4);
          iVar4 = (**(code **)local_11c->QueryInterface)(local_11c,&DAT_4544ab4c,&local_120);
          if (-1 < iVar4) {
            FUN_45423bc7(&local_128,&local_120);
          }
          pIVar10 = local_128;
          local_128 = (ITypeInfoVtbl *)0x0;
          *(ITypeInfoVtbl **)((int)this + 0xc) = pIVar10;
          if (DAT_4545fba8 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = DAT_4545fba8 + 4;
          }
          FUN_45424ffd(iVar4,FUN_454256ae,this);
          local_8._0_1_ = 3;
          if (local_120 != (int *)0x0) {
            (**(code **)(*local_120 + 8))(local_120);
          }
          local_8._0_1_ = 2;
          if (local_128 != (ITypeInfoVtbl *)0x0) {
            (**(code **)(local_128->QueryInterface + 8))(local_128);
          }
        }
        (*local_124->lpVtbl->Release)(local_124);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_11c != (ITypeInfoVtbl *)0x0) {
          (**(code **)(local_11c->QueryInterface + 8))(local_11c);
        }
      }
      goto LAB_45426153;
    }
    DVar5 = GetModuleFileNameA(DAT_45460800,local_118,0x104);
    if ((DVar5 == 0) || (DVar5 == 0x104)) goto LAB_45426153;
    local_11c = (ITypeInfoVtbl *)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    sVar6 = _strlen(local_118);
    local_120 = (int *)(sVar6 + 1);
    lVar7 = ATL::AtlMultiply<int>((int *)&local_120,(int)local_120,2);
    piVar2 = local_120;
    if (-1 < lVar7) {
      if (((int)local_120 < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_120), bVar3)) {
        pwVar8 = local_140;
        pIVar10 = (ITypeInfoVtbl *)0x0;
      }
      else {
        pwVar8 = (wchar_t *)FUN_454145c6(&local_11c,(int)piVar2);
        pIVar10 = local_11c;
      }
      pwVar8 = AtlA2WHelper(pwVar8,local_118,(uint)piVar2 >> 1,3);
      if (pwVar8 != (wchar_t *)0x0) {
        HVar9 = LoadTypeLib(pwVar8,&local_124);
        local_8 = local_8 & 0xffffff00;
        while (pIVar10 != (ITypeInfoVtbl *)0x0) {
          pIVar1 = (ITypeInfoVtbl *)pIVar10->QueryInterface;
          FID_conflict__free(pIVar10);
          pIVar10 = pIVar1;
        }
        goto LAB_4542605b;
      }
      while (pIVar10 != (ITypeInfoVtbl *)0x0) {
        pIVar1 = (ITypeInfoVtbl *)pIVar10->QueryInterface;
        FID_conflict__free(pIVar10);
        pIVar10 = pIVar1;
      }
    }
  }
  else {
LAB_45426153:
    if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) == 0)) {
      FUN_454264f8(this,*(undefined **)((int)this + 0xc));
    }
  }
  LeaveCriticalSection(local_130);
LAB_45426179:
  FUN_4542a957();
  return;
}


