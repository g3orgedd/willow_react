// Source: CLCiffConversion_Layout.dll @ 454396de; FUN_454396de

undefined4 __cdecl FUN_454396de(LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((code *)(DAT_45462710 ^ DAT_4545d9f0) != (code *)0x0) {
    uVar1 = (*(code *)(DAT_45462710 ^ DAT_4545d9f0))(param_1,param_2,param_3);
    return uVar1;
  }
  InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return 1;
}


