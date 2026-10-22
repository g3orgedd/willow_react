// Source: CLCiffConversion_Layout.dll @ 45412f6f; FUN_45412f6f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_45412f6f(int *param_1)

{
  int *piVar1;
  
  FUN_45416001((int)param_1);
  FUN_454223fd(param_1 + 3);
  FUN_45402c5d(param_1 + 2);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402c5d(param_1);
  return;
}


