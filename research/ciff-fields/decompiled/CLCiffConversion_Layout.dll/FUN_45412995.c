// Source: CLCiffConversion_Layout.dll @ 45412995; FUN_45412995

int * __thiscall FUN_45412995(void *this,int param_1)

{
  if (param_1 != 0) {
    *(undefined ***)this = &PTR_454498b0;
    FUN_454127a6((undefined4 *)((int)this + 0x10));
  }
  *(undefined ***)((int)this + *(int *)(*(int *)this + 4)) = CCIFFResolutionAdjust::vftable;
  *(int *)(*(int *)(*(int *)this + 4) + -4 + (int)this) = *(int *)(*(int *)this + 4) + -0x10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return this;
}


