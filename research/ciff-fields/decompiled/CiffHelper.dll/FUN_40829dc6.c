// Source: CiffHelper.dll @ 40829dc6; FUN_40829dc6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_40829dc6(void *this,undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
            int param_6)

{
  *(undefined4 *)((int)this + 4) = param_2;
  *(undefined4 *)this = param_1;
  *(double *)((int)this + 8) =
       (double)param_4 / _DAT_408500b0 + (double)param_3 + (double)param_5 / _DAT_408500b8 +
       (double)param_6 / _DAT_408500c8;
  return;
}


