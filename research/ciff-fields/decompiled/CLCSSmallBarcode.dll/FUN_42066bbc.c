// Source: CLCSSmallBarcode.dll @ 42066bbc; FUN_42066bbc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_42066bbc(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  
  piVar2 = param_3;
  puVar3 = &LAB_42087f4d;
  piVar6 = (int *)*param_3;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))();
    puVar4 = FUN_42036eb2(&param_3,piVar6);
    piVar6 = (int *)*puVar4;
    piVar1 = (int *)*param_2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1,piVar1);
    }
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1,piVar1);
    }
    uVar5 = (**(code **)(*piVar6 + 4))();
    if (param_3 != (int *)0x0) {
      (**(code **)*param_3)(1);
    }
    piVar2 = (int *)*piVar2;
    param_3 = (int *)0x0;
    puVar3 = (undefined1 *)(**(code **)(*piVar2 + 0xbc))(piVar2,uVar5);
  }
  return puVar3;
}


