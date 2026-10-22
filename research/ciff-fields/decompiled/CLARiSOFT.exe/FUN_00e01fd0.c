// Source: CLARiSOFT.exe @ 00e01fd0; FUN_00e01fd0

undefined4 * __thiscall FUN_00e01fd0(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_00e022f4(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_00e02099(-0x7ff8fff2);
    }
  }
  return this;
}


