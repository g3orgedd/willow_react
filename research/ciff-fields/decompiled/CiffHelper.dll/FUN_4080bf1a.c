// Source: CiffHelper.dll @ 4080bf1a; FUN_4080bf1a

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT FUN_4080bf1a(void)

{
  HRESULT HVar1;
  int unaff_EBP;
  void *unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    SysFreeString((BSTR)0x0);
    HVar1 = -0x7ff8fff2;
  }
  else {
    HVar1 = FUN_408040a6(unaff_EDI,*(BSTR *)(unaff_EBP + -0x14));
    SysFreeString(*(BSTR *)(unaff_EBP + -0x14));
  }
  return HVar1;
}


