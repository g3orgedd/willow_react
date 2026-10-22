// Source: CiffHelper.dll @ 4080c78f; FUN_4080c78f

int __thiscall FUN_4080c78f(void *this,undefined1 (*param_1) [16],int param_2)

{
  undefined1 (*pauVar1) [16];
  
  if (((-1 < param_2) && (param_2 <= *(int *)(*(int *)this + -8))) &&
     (pauVar1 = FUN_4082ea79((undefined1 (*) [16])(*(int *)this + param_2 * 2),param_1),
     pauVar1 != (undefined1 (*) [16])0x0)) {
    return (int)pauVar1 - *(int *)this >> 1;
  }
  return -1;
}


