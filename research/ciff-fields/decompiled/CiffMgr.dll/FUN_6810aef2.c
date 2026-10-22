// Source: CiffMgr.dll @ 6810aef2; FUN_6810aef2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_6810aef2(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x80004003;
  }
  else {
    piVar4 = (int *)0x0;
    piVar2 = (int *)0x8007000e;
    *param_1 = 0;
    puVar3 = (undefined4 *)FUN_68132c9e(0xc48);
    if (puVar3 != (undefined4 *)0x0) {
      piVar4 = FUN_6810a65b(puVar3);
    }
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 4;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      piVar2 = (int *)FUN_681046e7((int)piVar1);
      if (-1 < (int)piVar2) {
        piVar2 = FUN_6810b2fd((int)piVar4);
        if (-1 < (int)piVar2) {
          piVar2 = (int *)0x0;
        }
      }
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar4 + 0xe4))(1);
        piVar4 = (int *)0x0;
      }
    }
    *param_1 = piVar4;
  }
  return piVar2;
}


