// Source: CLCiffConversion_Data.dll @ 4502eca1; FUN_4502eca1

bool FUN_4502eca1(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar1 = DAT_45052354;
  if (DAT_45052354 < 0) {
    local_8 = 0;
    iVar1 = 0;
    if (((code *)(DAT_45056f74 ^ DAT_450518d0) != (code *)0x0) &&
       (iVar2 = (*(code *)(DAT_45056f74 ^ DAT_450518d0))(&local_8,0), iVar2 == 0x7a)) {
      iVar1 = 1;
    }
  }
  DAT_45052354 = iVar1;
  return 0 < DAT_45052354;
}


