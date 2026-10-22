// Source: CLCSSmallBarcode.dll @ 42065ee4; FUN_42065ee4

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_42065ee4(void *this,uint param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_42066cab(this,param_1);
  if ((char)uVar1 != '\0') {
    FUN_42009398(*(undefined4 **)this,param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_1 * 8;
  }
  return this;
}


