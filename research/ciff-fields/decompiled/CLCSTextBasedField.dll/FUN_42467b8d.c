// Source: CLCSTextBasedField.dll @ 42467b8d; FUN_42467b8d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_42467b8d(undefined4 *param_1)

{
  OLECHAR *pOVar1;
  int *piVar2;
  BSTR local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = ZipherBitmapFont::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  local_8 = 1;
  uStack_7 = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0x80000000;
  param_1[0xb] = 1;
  param_1[0xc] = 0;
  FUN_424037d2(param_1 + 0xd,L"");
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  _local_8 = CONCAT31(uStack_7,4);
  pOVar1 = FUN_42459daa();
  FUN_42403b70(param_1 + 0x11,pOVar1);
  piVar2 = (int *)FUN_42468007(param_1,local_14);
  FUN_4241115f(param_1 + 0xe,piVar2);
  SysFreeString(local_14[0]);
  return param_1;
}


