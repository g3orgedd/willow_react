// Source: CiffMgr.dll @ 681154da; FUN_681154da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_681154da(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    (**(code **)(*param_2 + 4))(param_2);
    param_2 = piVar1;
    FUN_68116e65((void *)(param_1 + 4),&param_2);
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


