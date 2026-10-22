// Source: CLCiffConversion_Data.dll @ 450148ff; FUN_450148ff

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_450148ff(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ATL::CComObject<CCiffConversion_Data>::vftable;
  param_1[1] = ATL::CComObject<CCiffConversion_Data>::vftable;
  param_1[2] = ATL::CComObject<CCiffConversion_Data>::vftable;
  param_1[3] = 0xc0000001;
  piVar1 = (int *)param_1[0xb];
  if (piVar1 != (int *)0x0) {
    param_1[0xb] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*DAT_45053870 + 8))();
  FUN_45014993((int)param_1);
  return;
}


