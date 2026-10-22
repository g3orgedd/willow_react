// Source: CLCiffConversion_Layout.dll @ 4540e34a; FUN_4540e34a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_4540e34a(undefined4 *param_1)

{
  char *pcVar1;
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
  FUN_454028ee(param_1 + 0xd,L"");
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  _local_8 = CONCAT31(uStack_7,4);
  pcVar1 = FUN_45408541();
  FUN_45402c99(param_1 + 0x11,pcVar1);
  piVar2 = (int *)FUN_4540e7c9(param_1,local_14);
  FUN_454066f3(param_1 + 0xe,piVar2);
  SysFreeString(local_14[0]);
  return param_1;
}


