// Source: CLCiffConversion_Data.dll @ 4502ec73; FUN_4502ec73

undefined4 __cdecl FUN_4502ec73(LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((code *)(DAT_45056f10 ^ DAT_450518d0) != (code *)0x0) {
    uVar1 = (*(code *)(DAT_45056f10 ^ DAT_450518d0))(param_1,param_2,param_3);
    return uVar1;
  }
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return 1;
}


