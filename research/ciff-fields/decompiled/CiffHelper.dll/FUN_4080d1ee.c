// Source: CiffHelper.dll @ 4080d1ee; FUN_4080d1ee

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4080d1ee(void *this,int *param_1)

{
  longlong lVar1;
  int iVar2;
  wchar_t *pwVar3;
  UINT UVar4;
  int iVar5;
  VARIANTARG local_88;
  int local_78;
  int local_74;
  int local_70;
  void *local_6c;
  int local_68;
  int local_64;
  int local_60;
  short local_5c [2];
  wchar_t local_58 [2];
  int local_54;
  wchar_t *local_50;
  int local_4c;
  BSTR local_48;
  BSTR local_44;
  int *local_40;
  wchar_t local_3c [26];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0;
  local_6c = this;
  FUN_40802e40(&local_44,L"");
  local_54 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*param_1 + 0x1c))(param_1,&local_54);
  if ((0 < local_54) && (iVar2 = 0, 0 < local_54)) {
    do {
      FUN_40802e76((uint *)&local_88);
      local_8._0_1_ = 2;
      local_64 = iVar2 + 1;
      (**(code **)(*param_1 + 0x24))(param_1,local_64,&local_88);
      CComQIPtr<>(&local_40,(undefined4 *)local_88.n1._8_4_);
      local_8._0_1_ = 3;
      (**(code **)(*local_40 + 0x7c))(local_40,&local_60);
      if (local_60 != 0) {
        (**(code **)(*local_40 + 0x24))(local_40,&local_74);
        if (local_74 == 0) {
          iVar2 = *(int *)((int)this + 0x7c);
          if (iVar2 < 1) {
            local_50 = (wchar_t *)0x0;
            local_8._0_1_ = 4;
            (**(code **)(*local_40 + 0x44))(local_40,&local_50);
            iVar2 = __wtol(local_50);
            local_8._0_1_ = 3;
            SysFreeString(local_50);
          }
          (**(code **)(*local_40 + 0x34))(local_40,&local_4c);
          lVar1 = (ulonglong)(local_4c + 1) * 2;
          pwVar3 = (wchar_t *)
                   FUN_4082c99b(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
          (**(code **)(*local_40 + 0x3c))(local_40,&local_68);
          if (local_68 == 0) {
            _swprintf_s(local_3c,0x14,L"%%ld");
          }
          else {
            (**(code **)(*local_40 + 0x2c))(local_40,local_5c);
            if (local_5c[0] == 0x30) {
              _swprintf_s(local_3c,0x14,L"%%0%dld");
            }
            else {
              _swprintf_s(local_3c,0x14,L"%%%dld",local_4c,local_4c);
            }
          }
          _swprintf_s(pwVar3,local_4c + 1,local_3c,iVar2);
          FUN_40803f8b(&local_44,pwVar3);
          FID_conflict__free(pwVar3);
        }
        else {
          (**(code **)(*local_40 + 0x3c))(local_40,&local_78);
          local_48 = (BSTR)0x0;
          local_8._0_1_ = 5;
          (**(code **)(*local_40 + 0x44))(local_40,&local_48);
          if (local_78 == 0) {
LAB_4080d433:
            FUN_408040a6(&local_44,local_48);
          }
          else {
            UVar4 = SysStringLen(local_48);
            (**(code **)(*local_40 + 0x34))(local_40,&local_70);
            if (local_70 <= (int)UVar4) goto LAB_4080d433;
            iVar5 = local_70 - UVar4;
            lVar1 = (ulonglong)(iVar5 + 1) * 2;
            pwVar3 = (wchar_t *)
                     FUN_4082c99b(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
            (**(code **)(*local_40 + 0x2c))(local_40,local_58);
            iVar2 = 0;
            if (0 < iVar5) {
              do {
                pwVar3[iVar2] = local_58[0];
                iVar2 = iVar2 + 1;
              } while (iVar2 < iVar5);
            }
            pwVar3[iVar2] = L'\0';
            FUN_40803f8b(&local_44,pwVar3);
            FUN_408040a6(&local_44,local_48);
            FID_conflict__free(pwVar3);
          }
          SysFreeString(local_48);
        }
      }
      local_8._0_1_ = 2;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))(local_40);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      VariantClear(&local_88);
      iVar2 = local_64;
      this = local_6c;
    } while (local_64 < local_54);
  }
  (**(code **)(*param_1 + 100))(param_1,local_44);
  (**(code **)(*param_1 + 0x5c))(param_1,local_44);
  SysFreeString(local_44);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4082d4c6();
  return;
}


