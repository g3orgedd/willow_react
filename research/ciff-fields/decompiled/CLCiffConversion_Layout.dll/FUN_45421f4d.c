// Source: CLCiffConversion_Layout.dll @ 45421f4d; FUN_45421f4d

uint __thiscall FUN_45421f4d(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 8) - *(int *)this >> 2;
  if (0x3fffffff - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (uVar1 < param_1) {
    uVar1 = param_1;
  }
  return uVar1;
}


