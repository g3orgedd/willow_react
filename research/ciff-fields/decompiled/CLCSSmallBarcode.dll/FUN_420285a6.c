// Source: CLCSSmallBarcode.dll @ 420285a6; FUN_420285a6

undefined4 * __thiscall FUN_420285a6(void *this,int param_1,undefined4 param_2,uint param_3)

{
  FUN_420127d5(this,param_1,param_1 * 0x45,param_3);
  *(undefined ***)this = CRSS14StackedOmnidirectional::vftable;
  *(int *)((int)this + 0x844) = param_1 * 0x32;
  *(undefined4 *)((int)this + 0x840) = param_2;
  return this;
}


