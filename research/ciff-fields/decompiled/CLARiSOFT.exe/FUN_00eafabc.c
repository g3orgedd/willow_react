// Source: CLARiSOFT.exe @ 00eafabc; FUN_00eafabc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_00eafabc(undefined4 *param_1)

{
  *param_1 = CCiffChecker::vftable;
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  if ((undefined4 *)param_1[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[4])(1);
  }
  SysFreeString((BSTR)param_1[8]);
  FUN_00eb76fc(param_1 + 6);
  FID_conflict__free((void *)param_1[6]);
  return;
}


