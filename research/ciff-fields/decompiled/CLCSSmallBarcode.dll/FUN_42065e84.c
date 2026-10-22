// Source: CLCSSmallBarcode.dll @ 42065e84; FUN_42065e84

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_42065e84(void *this,uint param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_42066c5e(this,param_1);
  if ((char)uVar1 != '\0') {
    FUN_42027390();
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_1 * 0xc;
  }
  return this;
}


