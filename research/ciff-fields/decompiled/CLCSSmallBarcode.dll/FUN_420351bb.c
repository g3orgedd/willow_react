// Source: CLCSSmallBarcode.dll @ 420351bb; FUN_420351bb

undefined4 __fastcall FUN_420351bb(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
  }
  return uVar1;
}


