// Source: CLCiffConversion_Data.dll @ 45031f08; FUN_45031f08

undefined4 FUN_45031f08(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar1 = &DAT_45052460;
  puVar2 = &DAT_45055ce8;
  do {
    if (puVar1[1] == 1) {
      *puVar1 = puVar2;
      puVar2 = puVar2 + 0x18;
      FUN_4502ec73((LPCRITICAL_SECTION)*puVar1,4000,0);
    }
    puVar1 = puVar1 + 2;
  } while ((int)puVar1 < 0x45052580);
  return 1;
}


