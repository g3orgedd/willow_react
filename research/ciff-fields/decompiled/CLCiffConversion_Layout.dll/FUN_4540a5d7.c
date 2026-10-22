// Source: CLCiffConversion_Layout.dll @ 4540a5d7; FUN_4540a5d7

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4540a5d7(void *this,uint param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_4540ce52(this,param_1);
  if ((char)uVar1 != '\0') {
    FUN_4540a389(*(undefined4 **)this,param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_1 * 8;
  }
  return this;
}


