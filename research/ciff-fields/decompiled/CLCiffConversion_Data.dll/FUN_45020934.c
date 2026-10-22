// Source: CLCiffConversion_Data.dll @ 45020934; FUN_45020934

uint __thiscall FUN_45020934(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 8) - *(int *)this >> 3;
  if (0x1fffffff - (uVar1 >> 1) < uVar1) {
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


