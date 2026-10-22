// Source: CiffHelper.dll @ 40812209; FUN_40812209

undefined4 * __thiscall FUN_40812209(void *this,undefined4 *param_1)

{
  BSTR local_c;
  wchar_t local_8 [2];
  
  if (*(int *)this == 7) {
    local_c = SysAllocStringLen(*(OLECHAR **)((int)this + 0x10),7);
    if (local_c == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_40802f26(-0x7ff8fff2);
    }
    local_8[0] = *(short *)((int)this + 4) + L'0';
    local_8[1] = 0;
    FUN_40803f8b(&local_c,local_8);
    *param_1 = local_c;
    SysFreeString((BSTR)0x0);
  }
  else {
    FUN_40803baf(param_1,(int *)((int)this + 0xc));
  }
  return param_1;
}


