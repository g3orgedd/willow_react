// Source: CLCiffConversion_Layout.dll @ 4542581b; FUN_4542581b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_4542581b(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  void *this;
  int *piVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    piVar2 = (int *)0x0;
    iVar1 = -0x7ff8fff2;
    *param_3 = 0;
    this = (void *)FUN_4542ee51(0x500);
    if (this != (void *)0x0) {
      piVar2 = FUN_45423c15(this,param_1);
    }
    if (piVar2 != (int *)0x0) {
      iVar1 = FUN_45428446((int)(piVar2 + 7));
      if (-1 < iVar1) {
        iVar1 = 0;
      }
      if ((-1 < iVar1) && (iVar1 = FUN_4541b7bf(piVar2 + 4), -1 < iVar1)) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) || (iVar1 = (**(code **)*piVar2)(piVar2,param_2,param_3), iVar1 != 0)) {
        (**(code **)(*piVar2 + 0xc))(1);
      }
    }
  }
  return iVar1;
}


