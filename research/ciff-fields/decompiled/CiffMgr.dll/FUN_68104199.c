// Source: CiffMgr.dll @ 68104199; FUN_68104199

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_68104199(void *this,LCID param_1)

{
  ITypeInfo *pIVar1;
  int iVar2;
  DWORD DVar3;
  HRESULT HVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *local_22c;
  ITypeInfo *local_228;
  ITypeLib *local_224;
  ITypeInfo *local_220;
  WCHAR local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x224;
  local_8 = 0x681041a8;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_68104390;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_6816703c + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    local_224 = (ITypeLib *)0x0;
    iVar2 = _InlineIsEqualGUID(&DAT_68167040,*(int **)((int)this + 4));
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      iVar2 = LoadRegTypeLib(*(GUID **)((int)this + 4),*(WORD *)((int)this + 8),
                             *(WORD *)((int)this + 10),param_1,&local_224);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_68167140,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_6810436f;
      iVar2 = LoadTypeLib(local_21c,&local_224);
    }
    if (-1 < iVar2) {
      local_220 = (ITypeInfo *)0x0;
      local_8._0_1_ = 1;
      HVar4 = (*local_224->lpVtbl->GetTypeInfoOfGuid)(local_224,*(GUID **)this,&local_220);
      if (-1 < HVar4) {
        local_228 = local_220;
        if (local_220 != (ITypeInfo *)0x0) {
          (*local_220->lpVtbl->AddRef)(local_220);
        }
        local_22c = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        HVar4 = (*local_220->lpVtbl->QueryInterface)(local_220,(IID *)&DAT_68147770,&local_22c);
        if (-1 < HVar4) {
          FUN_68103afd(&local_228,&local_22c);
        }
        pIVar1 = local_228;
        local_228 = (ITypeInfo *)0x0;
        *(ITypeInfo **)((int)this + 0xc) = pIVar1;
        if (DAT_6816703c == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_6816703c + 4;
        }
        FUN_68103f4f(iVar2,FUN_68103fac,this);
        local_8._0_1_ = 2;
        if (local_22c != (int *)0x0) {
          (**(code **)(*local_22c + 8))(local_22c);
        }
        local_8._0_1_ = 1;
        if (local_228 != (ITypeInfo *)0x0) {
          (*local_228->lpVtbl->Release)(local_228);
        }
      }
      (*local_224->lpVtbl->Release)(local_224);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_220 != (ITypeInfo *)0x0) {
        (*local_220->lpVtbl->Release)(local_220);
      }
    }
  }
LAB_6810436f:
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_68104530(this,*(undefined **)((int)this + 0xc));
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_68104390:
  FUN_681320d7();
  return;
}


