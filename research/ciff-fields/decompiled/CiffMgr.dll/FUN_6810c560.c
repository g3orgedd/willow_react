// Source: CiffMgr.dll @ 6810c560; FUN_6810c560

void __thiscall FUN_6810c560(void *this,size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_681024d6(-0x7ff8fff2);
}


