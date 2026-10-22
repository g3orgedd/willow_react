// Source: CLCiffConversion_Layout.dll @ 454258ce; FUN_454258ce

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_454258ce(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    piVar4 = (int *)0x0;
    iVar2 = -0x7ff8fff2;
    *param_3 = 0;
    puVar3 = (undefined4 *)FUN_4542ee51(0x4f0);
    if (puVar3 != (undefined4 *)0x0) {
      piVar4 = FUN_45423cc3(puVar3);
    }
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 3;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar2 = FUN_45428446((int)piVar1);
      if ((-1 < iVar2) && (iVar2 = FUN_4541b7bf(piVar4), -1 < iVar2)) {
        iVar2 = 0;
      }
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if ((iVar2 != 0) || (iVar2 = (**(code **)*piVar4)(piVar4,param_2,param_3), iVar2 != 0)) {
        (**(code **)(*piVar4 + 0x14))(1);
      }
    }
  }
  return iVar2;
}


