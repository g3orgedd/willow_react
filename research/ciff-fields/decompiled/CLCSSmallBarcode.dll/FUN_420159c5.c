// Source: CLCSSmallBarcode.dll @ 420159c5; FUN_420159c5

undefined4 * __thiscall
FUN_420159c5(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  FUN_42012e2b(this);
  *(undefined4 *)((int)this + 0x82c) = param_1;
  *(uint *)((int)this + 0x830) = param_4 & 0xff;
  *(undefined4 *)((int)this + 0x834) = param_2;
  *(undefined4 *)((int)this + 0x838) = param_3;
  *(undefined ***)this = CRSSBarcodeBase::vftable;
  *(undefined4 *)((int)this + 0x83c) = 0;
  return this;
}


