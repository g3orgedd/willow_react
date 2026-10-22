// Source: CLCiffConversion_Data.dll @ 4501528c; FUN_4501528c

void __thiscall FUN_4501528c(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45002735(-0x7ff8fff2);
}


