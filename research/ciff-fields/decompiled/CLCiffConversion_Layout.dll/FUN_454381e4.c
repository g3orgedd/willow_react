// Source: CLCiffConversion_Layout.dll @ 454381e4; FUN_454381e4

undefined4 __cdecl FUN_454381e4(undefined4 *param_1)

{
  int *piVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    return 0x16;
  }
  *param_1 = DAT_4545e480;
  return 0;
}


