// Source: CLCSRichTextBlockField.dll @ 41806fb8; FUN_41806fb8

void __thiscall FUN_41806fb8(void *this,GUID *param_1)

{
  BSTR pOVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_4184d5b0 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  pOVar1 = SysAllocString(local_88);
  *(BSTR *)this = pOVar1;
  if (pOVar1 != (BSTR)0x0) {
    FUN_41825bc8(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4180190a(-0x7ff8fff2);
}


