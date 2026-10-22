// Source: CLCiffConversion_Data.dll @ 45014218; FUN_45014218

int __thiscall FUN_45014218(void *this,uint param_1)

{
  if (param_1 < *(uint *)((int)this + 0x10)) {
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    return (int)(void *)((int)this + param_1 * 2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_45020fe3("invalid string position");
}


