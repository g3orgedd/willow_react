// Source: CiffMgr.dll @ 6810a989; FUN_6810a989

undefined4 * __fastcall FUN_6810a989(undefined4 *param_1)

{
  *param_1 = CEncryption::vftable;
  param_1[1] = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!_";
  param_1[2] = 0x19;
  param_1[3] = 10;
  param_1[4] = 0x400;
  param_1[5] = 0x10;
  return param_1;
}


