// Source: CLARiSOFT.exe @ 00e052c5; FUN_00e052c5

int __thiscall FUN_00e052c5(void *this,undefined1 (*param_1) [16],int param_2)

{
  undefined1 (*pauVar1) [16];
  
  if (((-1 < param_2) && (param_2 <= *(int *)(*(int *)this + -8))) &&
     (pauVar1 = FUN_00eccbcd((undefined1 (*) [16])(*(int *)this + param_2 * 2),param_1),
     pauVar1 != (undefined1 (*) [16])0x0)) {
    return (int)pauVar1 - *(int *)this >> 1;
  }
  return -1;
}


