// Source: CiffMgr.dll @ 6810afb0; FUN_6810afb0

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6810afb0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    piVar3 = (int *)0x0;
    iVar1 = -0x7ff8fff2;
    *param_1 = 0;
    puVar2 = (undefined4 *)FUN_68132c9e(0x58);
    if (puVar2 != (undefined4 *)0x0) {
      piVar3 = FUN_6810a690(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      iVar1 = FUN_681046e7((int)(piVar3 + 4));
      if ((-1 < iVar1) && (iVar1 = FUN_6810b451((int)piVar3), -1 < iVar1)) {
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        (**(code **)(*piVar3 + 0x50))(1);
        piVar3 = (int *)0x0;
      }
    }
    *param_1 = piVar3;
  }
  return iVar1;
}


