// Source: CLCiffConversion_Data.dll @ 4501486d; FUN_4501486d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_4501486d(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if ((*(byte *)(param_1 + 0x14) & 2) != 0) {
    for (piVar2 = *(int **)(param_1 + 8); piVar2 != *(int **)(param_1 + 0xc); piVar2 = piVar2 + 1) {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    FID_conflict__free(*(void **)(param_1 + 8));
  }
  piVar2 = *(int **)(param_1 + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return;
}


