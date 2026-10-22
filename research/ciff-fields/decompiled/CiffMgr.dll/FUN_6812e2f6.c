// Source: CiffMgr.dll @ 6812e2f6; FUN_6812e2f6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG __thiscall
FUN_6812e2f6(void *this,IUnknownVtbl *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,
            ULONG param_5)

{
  int *piVar1;
  bool bVar2;
  ULONG UVar3;
  DWORD DVar4;
  int iVar5;
  undefined1 (*pauVar6) [16];
  size_t sVar7;
  size_t _MaxCount;
  DWORD DVar8;
  HANDLE hObject;
  uint uVar9;
  code *pcVar10;
  _union_2683 local_54;
  _union_2683 local_44;
  DWORD local_34;
  int local_30;
  DWORD local_2c;
  BSTR local_28;
  int *local_24;
  uint local_20;
  int *local_1c;
  int *local_18;
  short local_14 [6];
  int local_8;
  undefined4 uStack_4;
  
  pcVar10 = GetTickCount_exref;
  uStack_4 = 0x44;
  local_8 = 0x6812e302;
  if ((param_1 == (IUnknownVtbl *)0x0) || (param_2 == (undefined4 *)0x0)) {
    UVar3 = 0x80004003;
  }
  else {
    local_2c = GetTickCount();
    FUN_6812e269((int)this);
    local_18 = (int *)0x0;
    local_8 = 0;
    UVar3 = FUN_68102520(&local_18);
    if (-1 < (int)UVar3) {
      DVar4 = GetTickCount();
      *(undefined4 *)((int)this + 4) = 0;
      *(DWORD *)((int)this + 0xb04) = DVar4 - local_2c;
      *(undefined4 *)((int)this + 8) = 1;
      if (local_18 == (int *)0x0) {
        UVar3 = 0x80004005;
      }
      else {
        local_28 = (BSTR)GetTickCount();
        UVar3 = (**(code **)(*local_18 + 0xfc))(local_18,0);
        if (-1 < (int)UVar3) {
          local_54._0_4_ = local_54._0_4_ & 0xffff0000;
          FUN_681242f0(&local_54,(OLECHAR *)param_1);
          local_8._0_1_ = 1;
          iVar5 = (**(code **)(*local_18 + 0xe8))
                            (local_18,local_54._0_4_,local_54.decVal.Hi32,local_54._8_4_,
                             local_54._12_4_,local_14);
          DVar4 = GetTickCount();
          *(DWORD *)((int)this + 0xb08) = DVar4 - (int)local_28;
          if ((iVar5 < 0) || (local_14[0] == 0)) {
            hObject = CreateFileW((LPCWSTR)param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                                  (HANDLE)0x0);
            if ((hObject == (HANDLE)0x0) || (hObject == (HANDLE)0xffffffff)) {
              UVar3 = 0x80030002;
            }
            else {
              CloseHandle(hObject);
              UVar3 = 0x80040240;
            }
          }
          else {
            local_24 = (int *)0x0;
            local_8._0_1_ = 2;
            uVar9 = 1;
            local_20 = 1;
            local_34 = GetTickCount();
            iVar5 = (**(code **)(*local_18 + 0x34))(local_18,&local_24);
            if (((iVar5 == 0) && (local_24 != (int *)0x0)) &&
               ((**(code **)(*local_24 + 0x28))(local_24,&local_30), local_30 == 7)) {
              CComQIPtr<>(&local_28,local_24);
              param_1 = (IUnknownVtbl *)0x0;
              local_8._0_1_ = 4;
              iVar5 = (**(code **)(*(int *)local_28 + 0x1c))(local_28,&param_1);
              if ((-1 < iVar5) &&
                 (bVar2 = FUN_68119d18(&param_1,(OLECHAR *)PTR_DAT_68160004), bVar2)) {
                FUN_68132710((uint *)&local_44,0,0x10);
                VariantInit((VARIANTARG *)&local_44.n2);
                local_8._0_1_ = 5;
                iVar5 = (**(code **)(*(int *)local_28 + 0x20))(local_28,&local_44);
                if ((-1 < iVar5) &&
                   ((local_44.n2.vt == 8 &&
                    (pauVar6 = FUN_68134a98((undefined1 (*) [16])local_44._8_4_,
                                            (undefined1 (*) [16])PTR_u_encoding___68160018),
                    uVar9 = local_20, pauVar6 != (undefined1 (*) [16])0x0)))) {
                  sVar7 = _wcslen((wchar_t *)PTR_u_encoding___68160018);
                  _MaxCount = _wcslen((wchar_t *)PTR_u_UTF_8_6816001c);
                  iVar5 = _wcsncmp((wchar_t *)(*pauVar6 + sVar7 * 2),(wchar_t *)PTR_u_UTF_8_6816001c
                                   ,_MaxCount);
                  local_20 = -(uint)(iVar5 != 0) & local_20;
                  uVar9 = local_20;
                }
                VariantClear((VARIANTARG *)&local_44.n2);
              }
              SysFreeString((BSTR)param_1);
              local_8._0_1_ = 2;
              if (local_28 != (BSTR)0x0) {
                (**(code **)(*(int *)local_28 + 8))(local_28);
              }
            }
            local_1c = (int *)0x0;
            local_8._0_1_ = 6;
            UVar3 = (**(code **)(*local_18 + 0xb4))(local_18,&local_1c);
            if ((-1 < (int)UVar3) && (local_1c != (int *)0x0)) {
              local_28 = (BSTR)0x0;
              local_8._0_1_ = 7;
              iVar5 = (**(code **)(*local_1c + 0x1c))(local_1c,&local_28);
              if ((iVar5 < 0) ||
                 (bVar2 = FUN_68119d18(&local_28,(OLECHAR *)PTR_u_ImageDesign_6815fc3c), !bVar2)) {
                UVar3 = 0x80030104;
              }
              else {
                param_1 = (IUnknownVtbl *)0x0;
                local_8 = CONCAT31(local_8._1_3_,8);
                UVar3 = (**(code **)*param_2)(param_2,&DAT_68148c38,&param_1);
                if (-1 < (int)UVar3) {
                  if (param_1 == (IUnknownVtbl *)0x0) {
                    UVar3 = 0x80004005;
                  }
                  else {
                    UVar3 = (**(code **)(param_1->QueryInterface + 0x8c))(param_1,uVar9);
                    if (-1 < (int)UVar3) {
                      DVar4 = GetTickCount();
                      *(DWORD *)((int)this + 0xb0c) = DVar4 - local_34;
                      DVar4 = GetTickCount();
                      UVar3 = FUN_68123a44(this,(SAFEARRAY *)&param_1,(int *)&local_1c,local_20);
                      DVar8 = GetTickCount();
                      *(DWORD *)((int)this + 0xb10) = DVar8 - DVar4;
                      if ((-1 < (int)UVar3) && (param_5 != 0)) {
                        DVar4 = GetTickCount();
                        UVar3 = FUN_68118e92(this,param_1,param_3,param_4);
                        DVar8 = GetTickCount();
                        *(DWORD *)((int)this + 0xb14) = DVar8 - DVar4;
                      }
                    }
                  }
                }
                local_8._0_1_ = 7;
                if (param_1 != (IUnknownVtbl *)0x0) {
                  (**(code **)(param_1->QueryInterface + 8))(param_1);
                }
              }
              SysFreeString(local_28);
            }
            local_8._0_1_ = 2;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
            local_8._0_1_ = 1;
            if (local_24 != (int *)0x0) {
              (**(code **)(*local_24 + 8))(local_24);
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          VariantClear((VARIANTARG *)&local_54.n2);
          pcVar10 = GetTickCount_exref;
        }
      }
      piVar1 = local_18;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      iVar5 = (*pcVar10)();
      *(DWORD *)((int)this + 0xb00) = iVar5 - local_2c;
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  return UVar3;
}


