// Source: CLCSBarcodeField.dll @ 4143ddd6; FUN_4143ddd6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

BSTR __thiscall FUN_4143ddd6(void *this,int param_1,BSTR param_2,BSTR param_3)

{
  int iVar1;
  BSTR pOVar2;
  BSTR pOVar3;
  
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  pOVar2 = this;
  pOVar3 = param_3;
  FUN_41402eab(&stack0xffffffd4,(int *)&param_2);
  iVar1 = FUN_4141445c(this,param_1,pOVar2,pOVar3);
  *(int *)((int)this + 4) = iVar1;
  SysFreeString(param_2);
  return this;
}


