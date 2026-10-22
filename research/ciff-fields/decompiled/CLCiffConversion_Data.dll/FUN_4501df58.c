// Source: CLCiffConversion_Data.dll @ 4501df58; FUN_4501df58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_4501df58(void *this,undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
            int param_6)

{
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)this = param_1;
  *(double *)((int)this + 8) =
       (double)param_4 / _DAT_45040c28 + (double)param_3 + (double)param_5 / _DAT_45040c30 +
       (double)param_6 / _DAT_45040c40;
  return;
}


