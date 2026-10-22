// Source: CLCSBarcodeField.dll @ 41448049; FUN_41448049

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_41448049(void *this,undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  FUN_41452089(this,param_1,param_2 * 0x22,param_4);
  *(undefined4 *)((int)this + 0x840) = 0;
  *(undefined ***)this = CRSSExpanded::vftable;
  *(int *)((int)this + 0x844) = param_2;
  FUN_414469cd((void *)((int)this + 0x848),1);
  *(undefined4 *)((int)this + 0x86c) = 0;
  *(undefined4 *)((int)this + 0x868) = param_3;
  *(undefined4 *)((int)this + 0x84c) = param_3;
  return this;
}


