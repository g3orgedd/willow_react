// Source: CLCiffConversion_Data.dll @ 45019f73; FUN_45019f73

undefined4 * __thiscall FUN_45019f73(void *this,undefined4 *param_1)

{
  BSTR local_c;
  wchar_t local_8 [2];
  
  if (*(int *)this == 7) {
    local_c = SysAllocStringLen(*(OLECHAR **)((int)this + 0x10),7);
    if (local_c == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_45002735(-0x7ff8fff2);
    }
    local_8[0] = *(short *)((int)this + 4) + L'0';
    local_8[1] = 0;
    FUN_45002522(&local_c,local_8);
    *param_1 = local_c;
    SysFreeString((BSTR)0x0);
  }
  else {
    FUN_45001ef3(param_1,(int *)((int)this + 0xc));
  }
  return param_1;
}


