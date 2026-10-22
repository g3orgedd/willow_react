// Source: CLCiffConversion_Data.dll @ 4502fda3; FUN_4502fda3

undefined4 __cdecl FUN_4502fda3(undefined4 *param_1)

{
  int *piVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    return 0x16;
  }
  *param_1 = DAT_45052368;
  return 0;
}


