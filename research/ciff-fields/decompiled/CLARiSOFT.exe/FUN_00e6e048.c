// Source: CLARiSOFT.exe @ 00e6e048; FUN_00e6e048

VARIANTARG * __thiscall FUN_00e6e048(void *this,undefined4 param_1)

{
  if (*(short *)this != 3) {
    VariantClear(this);
    *(undefined2 *)this = 3;
  }
  *(undefined4 *)((int)this + 8) = param_1;
  return this;
}


