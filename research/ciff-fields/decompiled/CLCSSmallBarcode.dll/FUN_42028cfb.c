// Source: CLCSSmallBarcode.dll @ 42028cfb; FUN_42028cfb

undefined4 * __thiscall FUN_42028cfb(void *this,int param_1,int param_2,char param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = 0x21;
  if (param_3 != '\0') {
    iVar1 = 0xd;
  }
  FUN_420127d5(this,param_1,iVar1 * param_1,param_4);
  *(undefined ***)this = CRSS14Standard::vftable;
  *(int *)((int)this + 0x844) = param_1 * 0x60;
  if (param_3 != '\0') {
    param_2 = param_1 * 0xd;
  }
  *(int *)((int)this + 0x840) = param_2;
  return this;
}


