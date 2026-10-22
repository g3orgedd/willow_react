// Source: CLCiffConversion_Layout.dll @ 454049b8; FUN_454049b8

undefined4 * __thiscall FUN_454049b8(void *this,uint param_1)

{
  void *pvVar1;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_454294b4("invalid string position");
  }
  *(uint *)((int)this + 0x10) = param_1;
  pvVar1 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar1 = *(void **)this;
  }
  *(undefined2 *)((int)pvVar1 + param_1 * 2) = 0;
  return this;
}


