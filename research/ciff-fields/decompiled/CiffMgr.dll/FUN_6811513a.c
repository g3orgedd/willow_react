// Source: CiffMgr.dll @ 6811513a; FUN_6811513a

undefined4 * __fastcall FUN_6811513a(undefined4 *param_1)

{
  FUN_68103c5f(param_1 + 4);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = ComCollectionImpl<ICalendarRule,ICalendarRules>::vftable;
  return param_1;
}


