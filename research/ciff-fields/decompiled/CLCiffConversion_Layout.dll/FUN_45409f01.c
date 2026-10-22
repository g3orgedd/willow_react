// Source: CLCiffConversion_Layout.dll @ 45409f01; FUN_45409f01

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_45409f01(void *this,undefined4 param_1,BSTR param_2)

{
  *(undefined ***)this = CVariableStore::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_45404d15((undefined4 *)((int)this + 4),(int *)&param_2);
  *(undefined4 *)((int)this + 0x10) = param_1;
  FUN_45401cab((void *)((int)this + 8),L"CurrentVariableData");
  FUN_45401cab((void *)((int)this + 0xc),L"PreviousVariableData");
  SysFreeString(param_2);
  return this;
}


