// Source: CLCiffConversion_Data.dll @ 450161cd; FUN_450161cd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_450161cd(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)0x0;
  iVar3 = -0x7ff8fff2;
  *param_3 = 0;
  puVar2 = (undefined4 *)FUN_45025ad0(0x4f8);
  if (puVar2 != (undefined4 *)0x0) {
    piVar4 = FUN_4501463a(puVar2);
  }
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar4 + 3;
    LOCK();
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    iVar3 = FUN_4501890c((int)piVar1);
    if (-1 < iVar3) {
      iVar3 = 0;
    }
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 0) && (iVar3 = (**(code **)*piVar4)(piVar4,param_2,param_3), iVar3 == 0)) {
      return 0;
    }
    (**(code **)(*piVar4 + 0x10))(1);
  }
  return iVar3;
}


