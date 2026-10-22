// Source: CLCiffConversion_Layout.dll @ 45416001; FUN_45416001

void __fastcall FUN_45416001(int param_1)

{
  int *_Memory;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2 != 0) {
    do {
      _Memory = *(int **)(*(int *)(param_1 + 0xc) + uVar1 * 4);
      if (_Memory != (int *)0x0) {
        FUN_45412fba(_Memory);
        FID_conflict__free(_Memory);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2));
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  return;
}


