// Source: CLCSSmallBarcode.dll @ 4202914d; FUN_4202914d

undefined4 * __thiscall FUN_4202914d(void *this,int param_1,undefined4 param_2,uint param_3)

{
  FUN_420159c5(this,param_1,param_1 * 10,0xd,param_3);
  *(undefined4 *)((int)this + 0x840) = param_2;
  *(undefined ***)this = CRSSLimited::vftable;
  *(int *)((int)this + 0x844) = *(int *)((int)this + 0x82c) * 0x4a;
  return this;
}


