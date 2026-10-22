// Source: CLCSGraphicPrimitive.dll @ 4280d201; FUN_4280d201

void __thiscall FUN_4280d201(void *this,GUID *param_1)

{
  BSTR pOVar1;
  OLECHAR local_88 [64];
  uint local_8;
  
  local_8 = DAT_4283cbb0 ^ (uint)&stack0xfffffffc;
  StringFromGUID2(param_1,local_88,0x40);
  pOVar1 = SysAllocString(local_88);
  *(BSTR *)this = pOVar1;
  if (pOVar1 != (BSTR)0x0) {
    FUN_42813a6e(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4280244e(-0x7ff8fff2);
}


