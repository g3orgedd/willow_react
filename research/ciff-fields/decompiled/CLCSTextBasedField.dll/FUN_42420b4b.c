// Source: CLCSTextBasedField.dll @ 42420b4b; FUN_42420b4b

void __thiscall FUN_42420b4b(void *this,GUID *param_1)

{
  BSTR pOVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  pOVar1 = SysAllocString(local_88);
  *(BSTR *)this = pOVar1;
  if (pOVar1 != (BSTR)0x0) {
    FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_42403fdf(-0x7ff8fff2);
}


