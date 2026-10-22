// Source: CLCSBarcodeField.dll @ 414139ad; FUN_414139ad

void __thiscall FUN_414139ad(void *this,GUID *param_1)

{
  BSTR pOVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  pOVar1 = SysAllocString(local_88);
  *(BSTR *)this = pOVar1;
  if (pOVar1 != (BSTR)0x0) {
    FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_41403850(-0x7ff8fff2);
}


