// Source: CLCiffConversion_Layout.dll @ 4540288a; FUN_4540288a

undefined4 * __thiscall FUN_4540288a(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_4540363b(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_45401d09(-0x7ff8fff2);
  }
  return this;
}


