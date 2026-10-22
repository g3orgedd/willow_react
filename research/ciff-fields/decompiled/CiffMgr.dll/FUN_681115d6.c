// Source: CiffMgr.dll @ 681115d6; FUN_681115d6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_681115d6(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    piVar4 = (int *)0x0;
    iVar2 = -0x7ff8fff2;
    *param_1 = 0;
    puVar3 = (undefined4 *)FUN_68132c9e(0x124);
    if (puVar3 != (undefined4 *)0x0) {
      piVar4 = FUN_68110906(puVar3);
    }
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 0x1b;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar2 = FUN_681046e7((int)piVar1);
      if (-1 < iVar2) {
        iVar2 = FUN_6811195d((int)piVar4);
        if (-1 < iVar2) {
          iVar2 = 0;
        }
      }
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 0) {
        (**(code **)(*piVar4 + 0x24))(1);
        piVar4 = (int *)0x0;
      }
    }
    *param_1 = piVar4;
  }
  return iVar2;
}


