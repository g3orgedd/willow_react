// Source: CLCiffConversion_Layout.dll @ 45412d96; FUN_45412d96

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_45412d96(int param_1)

{
  int *piVar1;
  
  FUN_4541613b(param_1);
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_4540460c((void *)(param_1 + 4),'\x01',0);
  return;
}


