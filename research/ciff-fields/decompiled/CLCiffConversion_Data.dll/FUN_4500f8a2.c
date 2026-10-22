// Source: CLCiffConversion_Data.dll @ 4500f8a2; FUN_4500f8a2

int __thiscall FUN_4500f8a2(void *this,undefined1 (*param_1) [16],int param_2)

{
  undefined1 (*pauVar1) [16];
  
  if (((-1 < param_2) && (param_2 <= *(int *)(*(int *)this + -8))) &&
     (pauVar1 = FUN_45022427((undefined1 (*) [16])(*(int *)this + param_2 * 2),param_1),
     pauVar1 != (undefined1 (*) [16])0x0)) {
    return (int)pauVar1 - *(int *)this >> 1;
  }
  return -1;
}


