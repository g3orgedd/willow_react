// Source: CLCiffConversion_Layout.dll @ 4543970c; FUN_4543970c

bool FUN_4543970c(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar1 = DAT_4545e530;
  if (DAT_4545e530 < 0) {
    local_8 = 0;
    iVar1 = 0;
    if (((code *)(DAT_45462774 ^ DAT_4545d9f0) != (code *)0x0) &&
       (iVar2 = (*(code *)(DAT_45462774 ^ DAT_4545d9f0))(&local_8,0), iVar2 == 0x7a)) {
      iVar1 = 1;
    }
  }
  DAT_4545e530 = iVar1;
  return 0 < DAT_4545e530;
}


