// Source: CLCiffConversion_Data.dll @ 45020ad4; FUN_45020ad4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_45020ad4(void *this,undefined4 param_1,BSTR param_2)

{
  *(undefined ***)this = CVariableStore::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  FUN_450022ea((undefined4 *)((int)this + 4),(int *)&param_2);
  *(undefined4 *)((int)this + 0x10) = param_1;
  FUN_45002326((void *)((int)this + 8),L"CurrentVariableData");
  FUN_45002326((void *)((int)this + 0xc),L"PreviousVariableData");
  SysFreeString(param_2);
  return this;
}


