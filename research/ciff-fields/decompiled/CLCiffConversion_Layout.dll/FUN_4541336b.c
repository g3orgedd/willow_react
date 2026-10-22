// Source: CLCiffConversion_Layout.dll @ 4541336b; FUN_4541336b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4541336b(void *this,int *param_1,int *param_2,int *param_3)

{
  void *this_00;
  
  this_00 = (void *)FUN_454298b4(0xc);
  if (this_00 == (void *)0x0) {
    param_3 = (int *)0x0;
  }
  else {
    param_3 = FUN_45412cef(this_00,param_1,param_2,param_3);
  }
  FUN_4542273a((void *)((int)this + 0x18),&param_3);
  *(undefined1 *)((int)this + 0x15) = 0;
  return;
}


