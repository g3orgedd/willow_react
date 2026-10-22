// Source: CLCiffConversion_Layout.dll @ 454126f9; FUN_454126f9

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_454126f9(void *this,int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_4540ce07(this,param_1[1] - *param_1 >> 2);
  if ((char)uVar1 != '\0') {
    piVar2 = FUN_45412339((int *)*param_1,(int *)param_1[1],*(int **)this);
    *(int **)((int)this + 4) = piVar2;
  }
  return this;
}


