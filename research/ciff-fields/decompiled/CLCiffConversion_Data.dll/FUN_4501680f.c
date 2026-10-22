// Source: CLCiffConversion_Data.dll @ 4501680f; FUN_4501680f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4501680f(void *this,LCID param_1)

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
  local_8 = 0x4501681e;
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) != 0)) goto LAB_45016a06;
  lpCriticalSection = (LPCRITICAL_SECTION)(DAT_45053870 + 0x10);
  local_8 = 0;
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)((int)this + 0xc) == 0) {
    local_224 = (ITypeLib *)0x0;
    iVar2 = FUN_45018a9f(&DAT_45053874,*(int **)((int)this + 4));
    if (((iVar2 == 0) || (*(short *)((int)this + 8) != -1)) || (*(short *)((int)this + 10) != -1)) {
      iVar2 = LoadRegTypeLib(*(GUID **)((int)this + 4),*(WORD *)((int)this + 8),
                             *(WORD *)((int)this + 10),param_1,&local_224);
    }
    else {
      DVar3 = GetModuleFileNameW(DAT_45054fec,local_21c,0x104);
      if ((DVar3 == 0) || (DVar3 == 0x104)) goto LAB_450169e5;
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
        HVar4 = (*local_220->lpVtbl->QueryInterface)(local_220,(IID *)&DAT_4503fddc,&local_22c);
        if (-1 < HVar4) {
          FUN_45014510(&local_228,&local_22c);
        }
        pIVar1 = local_228;
        local_228 = (ITypeInfo *)0x0;
        *(ITypeInfo **)((int)this + 0xc) = pIVar1;
        if (DAT_45053870 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = DAT_45053870 + 4;
        }
        FUN_4501584f(iVar2,FUN_45015f44,this);
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
LAB_450169e5:
  if ((*(int *)((int)this + 0xc) != 0) && (*(int *)((int)this + 0x14) == 0)) {
    FUN_45016db5(this,*(undefined **)((int)this + 0xc));
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_45016a06:
  FUN_45022eb8();
  return;
}


