// Source: CLCiffConversion_Data.dll @ 4500aeef; FUN_4500aeef

VARIANTARG * __thiscall FUN_4500aeef(void *this,undefined4 param_1)

{
  if (*(short *)this != 3) {
    VariantClear(this);
    *(undefined2 *)this = 3;
  }
  *(undefined4 *)((int)this + 8) = param_1;
  return this;
}


