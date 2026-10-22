// Source: CLCSSmallBarcode.dll @ 4200bd86; FUN_4200bd86

void FUN_4200bd86(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + param_2) = *(undefined1 *)((~uVar1 & 3) + param_1);
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 4);
  return;
}


