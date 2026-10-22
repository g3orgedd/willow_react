// Source: CLCSBarcodeField.dll @ 41413d27; FUN_41413d27

undefined4 * __thiscall FUN_41413d27(void *this,undefined4 *param_1)

{
  BSTR local_c;
  wchar_t local_8 [2];
  
  if (*(int *)this == 7) {
    local_c = SysAllocStringLen(*(OLECHAR **)((int)this + 0x10),7);
    if (local_c == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_41403850(-0x7ff8fff2);
    }
    local_8[0] = *(short *)((int)this + 4) + L'0';
    local_8[1] = 0;
    FUN_4140363d(&local_c,local_8);
    *param_1 = local_c;
    SysFreeString((BSTR)0x0);
  }
  else {
    FUN_41402eab(param_1,(int *)((int)this + 0xc));
  }
  return param_1;
}


