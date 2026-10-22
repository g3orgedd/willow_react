// Source: CLCSSmallBarcode.dll @ 42022692; FUN_42022692

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

BSTR __thiscall FUN_42022692(void *this,int param_1,BSTR param_2,BSTR param_3)

{
  int iVar1;
  BSTR pOVar2;
  BSTR pOVar3;
  
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  pOVar2 = this;
  pOVar3 = param_3;
  FUN_42002e4a(&stack0xffffffd4,(int *)&param_2);
  iVar1 = FUN_42022f72(this,param_1,pOVar2,pOVar3);
  *(int *)((int)this + 4) = iVar1;
  SysFreeString(param_2);
  return this;
}


