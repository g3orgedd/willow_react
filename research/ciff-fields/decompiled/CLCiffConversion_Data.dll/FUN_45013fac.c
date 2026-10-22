// Source: CLCiffConversion_Data.dll @ 45013fac; FUN_45013fac

rsize_t __thiscall
FUN_45013fac(void *this,wchar_t *param_1,rsize_t param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 <= *(uint *)((int)this + 0x10)) {
    uVar1 = *(uint *)((int)this + 0x10) - param_4;
    if (uVar1 < param_3) {
      param_3 = uVar1;
    }
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    FUN_45013ff1(param_1,param_2,(wchar_t *)((int)this + param_4 * 2),param_3);
    return param_3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45020fe3("invalid string position");
}


