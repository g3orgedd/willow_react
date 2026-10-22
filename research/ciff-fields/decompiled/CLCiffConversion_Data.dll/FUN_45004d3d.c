// Source: CLCiffConversion_Data.dll @ 45004d3d; FUN_45004d3d

undefined4 * __thiscall FUN_45004d3d(void *this,uint param_1)

{
  void *pvVar1;
  
  if (*(uint *)((int)this + 0x10) < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fe3("invalid string position");
  }
  *(uint *)((int)this + 0x10) = param_1;
  pvVar1 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
    pvVar1 = *(void **)this;
  }
  *(undefined1 *)((int)pvVar1 + param_1) = 0;
  return this;
}


