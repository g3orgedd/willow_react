// Source: CLARiSOFT.exe @ 00e2e31a; FUN_00e2e31a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_00e2e31a(void *this,int param_1)

{
  size_t sVar1;
  LPCSTR pCVar2;
  wchar_t *pwVar3;
  LPCWSTR local_2c;
  wchar_t *local_28;
  wchar_t *local_24;
  LPCWSTR local_20;
  LPCWSTR local_1c;
  LPCWSTR local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0xe2e326;
  local_2c = this;
  if (param_1 == -4) {
    FUN_00eb9380(local_18,0x630b);
    local_8 = 9;
    FUN_00eb9380(&local_2c,0x630e);
    MessageBoxW((HWND)0x0,local_2c,local_18[0],0x31);
    FUN_00e01f81((int *)&local_2c);
    FUN_00e01f81((int *)local_18);
    goto LAB_00e2e5bf;
  }
  if (param_1 == -3) {
    local_28 = (wchar_t *)0x0;
    local_8 = 5;
    (**(code **)(**(int **)((int)this + 0x160) + 0x1c))();
    pwVar3 = local_28;
    if (local_28 == (wchar_t *)0x0) {
LAB_00e2e4ba:
      pCVar2 = (LPCSTR)0x0;
    }
    else {
      sVar1 = _wcslen(local_28);
      if (0x3fffffff < (int)(sVar1 + 1)) goto LAB_00e2e4ba;
      pCVar2 = FUN_00e04276(&stack0xffffffbc,pwVar3,(sVar1 + 1) * 2,3);
    }
    FUN_00e03b6d(local_18,pCVar2);
    local_24 = (wchar_t *)PTR_DAT_00f35014;
    local_8._0_1_ = 7;
    FUN_00e052f9(&local_24,L"%d");
    FUN_00eb9380(&local_1c,0x6309);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_00eb928f(&local_20,0x630d);
    MessageBoxW((HWND)0x0,local_20,local_1c,0x31);
    FUN_00e01f81((int *)&local_20);
    FUN_00e01f81((int *)&local_1c);
    FUN_00e01f81((int *)&local_24);
    FUN_00e01f81((int *)local_18);
    pwVar3 = local_28;
  }
  else {
    if (param_1 == -2) {
      FUN_00eb9380(&local_1c,0x630b);
      local_8 = 4;
      FUN_00eb9380(&local_20,0x630c);
      MessageBoxW((HWND)0x0,local_20,local_1c,0x10);
      FUN_00e01f81((int *)&local_20);
      FUN_00e01f81((int *)&local_1c);
      goto LAB_00e2e5bf;
    }
    if (param_1 != -1) goto LAB_00e2e5bf;
    local_24 = (wchar_t *)0x0;
    local_8 = 0;
    (**(code **)(**(int **)((int)this + 0x160) + 0x1c))();
    pwVar3 = local_24;
    if (local_24 == (wchar_t *)0x0) {
LAB_00e2e381:
      pCVar2 = (LPCSTR)0x0;
    }
    else {
      sVar1 = _wcslen(local_24);
      if (0x3fffffff < (int)(sVar1 + 1)) goto LAB_00e2e381;
      pCVar2 = FUN_00e04276(&stack0xffffffbc,pwVar3,(sVar1 + 1) * 2,3);
    }
    FUN_00e03b6d(&local_20,pCVar2);
    local_28 = (wchar_t *)PTR_DAT_00f35014;
    local_8._0_1_ = 2;
    FUN_00e052f9(&local_28,L"%d");
    FUN_00eb9380(&local_1c,0x6309);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00eb928f(local_18,0x630a);
    MessageBoxW((HWND)0x0,local_18[0],local_1c,0x31);
    FUN_00e01f81((int *)local_18);
    FUN_00e01f81((int *)&local_1c);
    FUN_00e01f81((int *)&local_28);
    FUN_00e01f81((int *)&local_20);
    pwVar3 = local_24;
  }
  SysFreeString(pwVar3);
LAB_00e2e5bf:
  FUN_00ec9e3c();
  return;
}


