// Source: CLCSTextBasedField.dll @ 424258a9; FUN_424258a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_424258a9(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = param_2;
  piVar1 = (int *)*param_1;
  if ((piVar1 != (int *)0x0) && (*param_2 != 0)) {
    param_1 = (int *)0x0;
    iVar2 = (**(code **)(*piVar1 + 0x150))(piVar1,&param_1);
    if (-1 < iVar2) {
      FUN_42458671(&param_2);
      piVar3 = (int *)*piVar3;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      iVar2 = FUN_42459491((int)param_1,0,piVar3);
      FUN_42458752(&param_2);
      return iVar2;
    }
  }
  return 0;
}


