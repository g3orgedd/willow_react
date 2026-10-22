// Source: CLCSSmallBarcode.dll @ 42027c0a; FUN_42027c0a

undefined4 * __thiscall FUN_42027c0a(void *this,int param_1,uint param_2)

{
  FUN_420127d5(this,param_1,param_1 * 0xd,param_2);
  *(int *)((int)this + 0x840) = param_1 * 0xd;
  *(undefined ***)this = CRSS14Stacked::vftable;
  *(int *)((int)this + 0x848) = param_1 * 0x32;
  return this;
}


