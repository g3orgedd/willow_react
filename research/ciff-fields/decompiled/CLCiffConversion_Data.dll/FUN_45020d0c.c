// Source: CLCiffConversion_Data.dll @ 45020d0c; FUN_45020d0c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_45020d0c(void *this,BSTR param_1,BSTR param_2,void *param_3)

{
  int iVar1;
  BSTR extraout_ECX;
  BSTR pOVar2;
  BSTR pOVar3;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 1;
  pOVar3 = this;
  FUN_45001ef3(&stack0xffffffd0,(int *)&param_2);
  local_8._0_1_ = 2;
  pOVar2 = extraout_ECX;
  FUN_45001ef3(&stack0xffffffcc,(int *)&param_1);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45020c83(local_14,pOVar2,pOVar3);
  iVar1 = Open(param_3,*(HKEY *)((int)this + 0x10),local_14[0],0x20019);
  SysFreeString(local_14[0]);
  SysFreeString(param_1);
  SysFreeString(param_2);
  return (bool)('\x01' - (iVar1 != 0));
}


