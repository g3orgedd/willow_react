// Source: CLCiffConversion_Data.dll @ 4500570c; FUN_4500570c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_4500570c(int param_1)

{
  int *piVar1;
  
  FUN_450067f1(param_1);
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_450046d9((void *)(param_1 + 4),'\x01',0);
  return;
}


