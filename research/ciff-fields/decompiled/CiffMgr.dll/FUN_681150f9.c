// Source: CiffMgr.dll @ 681150f9; FUN_681150f9

undefined4 * __fastcall FUN_681150f9(undefined4 *param_1)

{
  FUN_68103c5f(param_1 + 4);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = ComCollectionImpl<IDayMonth,IAvoidanceDates>::vftable;
  return param_1;
}


