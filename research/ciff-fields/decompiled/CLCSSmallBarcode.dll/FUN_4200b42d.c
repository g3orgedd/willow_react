// Source: CLCSSmallBarcode.dll @ 4200b42d; FUN_4200b42d

undefined4 __fastcall FUN_4200b42d(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x2c) == 0x5a) || (*(int *)(param_1 + 0x2c) == 0x10e)) {
    uVar2 = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(param_1 + 0x78) = uVar2;
  }
  uVar2 = FUN_420270a6();
  if ((*(int *)(param_1 + 0x2c) == 0x5a) || (*(int *)(param_1 + 0x2c) == 0x10e)) {
    uVar1 = *(undefined4 *)(param_1 + 0x70);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(param_1 + 0x78) = uVar1;
  }
  return uVar2;
}


