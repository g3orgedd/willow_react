// Source: CiffMgr.dll @ 6810bbed; FUN_6810bbed

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_6810bbed(void *this,undefined4 param_1)

{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined ***)this = ATL::CComAggObject<CCiffManager>::vftable;
  FUN_6810bc2c((void *)((int)this + 0xc),param_1);
  (**(code **)(*DAT_6816703c + 4))();
  return this;
}


