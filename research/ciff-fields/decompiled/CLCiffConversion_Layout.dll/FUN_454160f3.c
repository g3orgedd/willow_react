// Source: CLCiffConversion_Layout.dll @ 454160f3; FUN_454160f3

void __fastcall FUN_454160f3(int param_1)

{
  int *_Memory;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2 != 0) {
    do {
      _Memory = *(int **)(*(int *)(param_1 + 0x18) + uVar1 * 4);
      if (_Memory != (int *)0x0) {
        FUN_45413136(_Memory);
        FID_conflict__free(_Memory);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2));
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x15) = 0;
  return;
}


