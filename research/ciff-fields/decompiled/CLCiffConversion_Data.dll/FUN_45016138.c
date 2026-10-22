// Source: CLCiffConversion_Data.dll @ 45016138; FUN_45016138

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_45016138(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *this;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)0x0;
  iVar2 = -0x7ff8fff2;
  *param_3 = 0;
  this = (void *)FUN_45025ad0(0x508);
  if (this != (void *)0x0) {
    piVar1 = FUN_4501458c(this,param_1);
  }
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_4501890c((int)(piVar1 + 7));
    if (-1 < iVar2) {
      iVar2 = 0;
    }
    if (-1 < iVar2) {
      iVar2 = 0;
    }
    if ((iVar2 == 0) && (iVar2 = (**(code **)*piVar1)(piVar1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    (**(code **)(*piVar1 + 0xc))(1);
  }
  return iVar2;
}


