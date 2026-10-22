// Source: CiffMgr.dll @ 6812e0c7; FUN_6812e0c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_6812e0c7(undefined4 *param_1)

{
  *param_1 = ATL::CComObject<CSafeArrayStream>::vftable;
  param_1[1] = 0xc0000001;
  FUN_68130c20((int)param_1);
  (**(code **)(*DAT_6816703c + 8))();
  FUN_68103d54((int)(param_1 + 1));
  return;
}


