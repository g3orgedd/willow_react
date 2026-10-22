// Source: CLCSTextBasedField.dll @ 4243b565; FUN_4243b565

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4243b565(int param_1)

{
  wchar_t *pwVar1;
  undefined1 *puVar2;
  undefined1 local_26c [300];
  undefined1 local_140 [312];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x25c;
  local_8 = 0x4243b574;
  if (*(int *)(param_1 + 0x200) == 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x20;
  }
  else {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;
  }
  if (*(char *)(param_1 + 4) == '\0') {
    FUN_4245fb26(local_26c,0x809,0,1);
    local_8 = 1;
    pwVar1 = (wchar_t *)SysStringLen(*(BSTR *)(param_1 + 0x38));
    FUN_42460683(local_26c,*(HDC *)(param_1 + 8),*(HFONT *)(param_1 + 0x38),pwVar1,
                 *(LPRECT *)(param_1 + 0x204),*(uint *)(param_1 + 0x30));
    puVar2 = local_26c;
  }
  else {
    FUN_4245fb26(local_140,0x809,2,1);
    local_8 = 0;
    pwVar1 = (wchar_t *)SysStringLen(*(BSTR *)(param_1 + 0x38));
    FUN_42460683(local_140,*(HDC *)(param_1 + 8),*(HFONT *)(param_1 + 0x38),pwVar1,
                 *(LPRECT *)(param_1 + 0x204),*(uint *)(param_1 + 0x30));
    puVar2 = local_140;
  }
  local_8 = 0xffffffff;
  FUN_4245fcc0((int)puVar2);
  FUN_4246ecf6();
  return;
}


