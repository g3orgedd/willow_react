// Source: CLARiSOFT.exe @ 00e03ab8; FUN_00e03ab8

undefined4 * __thiscall FUN_00e03ab8(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_00e022f4(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_00e02099(-0x7ff8fff2);
  }
  return this;
}


