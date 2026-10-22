// Source: CLCiffConversion_Data.dll @ 4501cffb; FUN_4501cffb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * __thiscall FUN_4501cffb(void *this,wchar_t *param_1,ushort param_2,short param_3)

{
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)this = 0;
  FID_conflict_assign(this,param_1);
  *(ushort *)((int)this + 0x18) = param_3 << 10 | param_2;
  return this;
}


