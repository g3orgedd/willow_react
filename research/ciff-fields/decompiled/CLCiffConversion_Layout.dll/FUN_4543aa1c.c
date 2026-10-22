// Source: CLCiffConversion_Layout.dll @ 4543aa1c; FUN_4543aa1c

undefined4 FUN_4543aa1c(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar1 = &DAT_4545e580;
  puVar2 = &DAT_45461500;
  do {
    if (puVar1[1] == 1) {
      *puVar1 = puVar2;
      puVar2 = puVar2 + 0x18;
      FUN_454396de((LPCRITICAL_SECTION)*puVar1,4000,0);
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x4545e6a0);
  return 1;
}


