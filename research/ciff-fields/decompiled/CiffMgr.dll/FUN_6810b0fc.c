// Source: CiffMgr.dll @ 6810b0fc; FUN_6810b0fc

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6810b0fc(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = -0x7ff8fff2;
    *param_1 = 0;
    puVar3 = (undefined4 *)FUN_68132c9e(0x30);
    if (puVar3 == (undefined4 *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_6810a6fa(puVar3);
    }
    if (piVar4 != (int *)0x0) {
      piVar1 = piVar4 + 4;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar2 = FUN_681046e7((int)piVar1);
      if (-1 < iVar2) {
        iVar2 = 0;
      }
      LOCK();
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 != 0) {
        (**(code **)(*piVar4 + 0x3c))(1);
        piVar4 = (int *)0x0;
      }
    }
    *param_1 = piVar4;
  }
  return iVar2;
}


