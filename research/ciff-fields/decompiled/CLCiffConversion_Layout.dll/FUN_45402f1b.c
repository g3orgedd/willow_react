// Source: CLCiffConversion_Layout.dll @ 45402f1b; FUN_45402f1b

void __thiscall FUN_45402f1b(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45401d09(-0x7ff8fff2);
}


