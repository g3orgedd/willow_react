// Source: CiffMgr.dll @ 6810f023; FUN_6810f023

undefined4 FUN_6810f023(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_6810d62a(&DAT_681670d8,(int *)&PTR_DAT_6815f198,param_1,(undefined4 *)&DAT_6814914c);
    DisableThreadLibraryCalls(param_1);
  }
  else if (param_2 == 0) {
    FUN_6810ea7e(0x681670d8);
  }
  return 1;
}


