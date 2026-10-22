// Source: CLCSSmallBarcode.dll @ 42034d59; FUN_42034d59

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_42034d59(byte *param_1,byte *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int local_20 [6];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_8 = 0;
  FUN_42034dac(param_1,local_20,(int)param_2,param_4);
  uVar1 = FUN_42034bdd(local_20,param_2,param_3);
  FUN_42034732((int)local_20);
  return uVar1;
}


