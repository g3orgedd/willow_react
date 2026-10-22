// Source: CLCiffConversion_Data.dll @ 450147fc; FUN_450147fc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_450147fc(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ATL::CComAggObject<CCiffConversion_Data>::vftable;
  param_1[1] = 0xc0000001;
  piVar1 = (int *)param_1[0xf];
  if (piVar1 != (int *)0x0) {
    param_1[0xf] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*DAT_45053870 + 8))();
  FUN_45014993((int)(param_1 + 4));
  return;
}


