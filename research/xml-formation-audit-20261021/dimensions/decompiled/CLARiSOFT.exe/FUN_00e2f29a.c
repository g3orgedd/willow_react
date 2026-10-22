// Source: CLARiSOFT.exe @ 00e2f29a; FUN_00e2f29a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_00e2f29a(void *this,char param_1,int *param_2)

{
  int *piVar1;
  wchar_t *_Str;
  int iVar2;
  LPCWSTR pWVar3;
  int *piVar4;
  size_t sVar5;
  undefined4 *puVar6;
  BSTR extraout_ECX;
  BSTR pOVar7;
  CHAR local_44 [16];
  _union_2683 local_34;
  IErrorInfo *local_24;
  LPCWSTR local_20;
  int *local_1c;
  BSTR local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0;
  if (*(int *)((int)this + 0x158) != 0) {
    piVar4 = (int *)((int)this + 0x1e0);
    if (*piVar4 != 0) {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        *piVar4 = 0;
        (**(code **)(*piVar1 + 8))();
      }
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        *piVar4 = 0;
        (**(code **)(*piVar1 + 8))();
      }
    }
    iVar2 = (**(code **)(**(int **)((int)this + 0x230) + 0x20))
                      (*(int **)((int)this + 0x230),*(undefined4 *)(*(int *)((int)this + 0x158) + 8)
                      );
    if ((iVar2 < 0) || (*piVar4 == 0)) {
      local_20 = (LPCWSTR)PTR_DAT_00f35014;
      local_8._0_1_ = 7;
      piVar4 = FUN_00eb9380(&local_1c,0x619e);
      local_8._0_1_ = 8;
      FUN_00e06f61(&local_20,piVar4);
      FUN_00e01f81((int *)&local_1c);
      local_24 = (IErrorInfo *)0x0;
      local_18[0] = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,9);
      GetErrorInfo(0,&local_24);
      _Str = *(wchar_t **)(*(int *)((int)this + 0x158) + 8);
      if (_Str != (wchar_t *)0x0) {
        sVar5 = _wcslen(_Str);
        if ((int)(sVar5 + 1) < 0x40000000) {
          FUN_00e04276(local_44,_Str,(sVar5 + 1) * 2,3);
        }
      }
      puVar6 = FUN_00eb928f(&local_1c,0x7020);
      MessageBoxW((HWND)0x0,(LPCWSTR)*puVar6,local_20,0x10);
      FUN_00e01f81((int *)&local_1c);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    iVar2 = FUN_00e353ea(this,(int *)(*(int *)((int)this + 0x158) + 4));
    if (-1 < iVar2) {
      pWVar3 = (LPCWSTR)FUN_00e2f82e((int)this);
      local_20 = pWVar3;
      if (pWVar3 != (LPCWSTR)0x0) {
        (**(code **)(*(int *)pWVar3 + 4))();
      }
      local_8._0_1_ = 1;
      if (pWVar3 != (LPCWSTR)0x0) {
        if ((param_2 != (int *)0x0) && (param_1 == '\0')) {
          FUN_00e03b51((uint *)&local_34);
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*param_2 + 0x24))(param_2,1);
          if (-1 < iVar2) {
            local_34.n2.vt = 9;
            CComQIPtr<>(&local_1c,(undefined4 *)local_34._8_4_);
            if (local_1c != (int *)0x0) {
              local_18[0] = (BSTR)0x0;
              local_8._0_1_ = 4;
              iVar2 = (**(code **)(*local_1c + 0x4c))(local_1c);
              if (-1 < iVar2) {
                FUN_00e2f762((int *)&local_20,local_18,(void *)((int)this + 0x15c));
              }
              SysFreeString(local_18[0]);
            }
            local_8._0_1_ = 2;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))();
            }
          }
          local_8._0_1_ = 1;
          VariantClear((VARIANTARG *)&local_34.n2);
        }
        if (*(int *)((int)this + 0x15c) == 0) {
          local_18[0] = (BSTR)0x0;
          local_8._0_1_ = 5;
          FUN_00e2fc4e(local_18);
          FUN_00e2f762((int *)&local_20,local_18,(int *)((int)this + 0x15c));
          local_8._0_1_ = 1;
          SysFreeString(local_18[0]);
        }
      }
      FUN_00e3532f((int)this);
      FUN_00e30971((int)this);
      local_24 = (IErrorInfo *)0x0;
      local_8._0_1_ = 6;
      (**(code **)(**(int **)((int)this + 0x15c) + 0x1c))(*(int **)((int)this + 0x15c));
      pOVar7 = extraout_ECX;
      FUN_00e03ab8(&stack0xffffffb8,(int *)&local_24);
      FUN_00e350dc(pOVar7);
      SysFreeString((BSTR)local_24);
      local_8 = (uint)local_8._1_3_ << 8;
      if (pWVar3 != (LPCWSTR)0x0) {
        (**(code **)(*(int *)pWVar3 + 8))();
      }
    }
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  FUN_00ec9e3c();
  return;
}


