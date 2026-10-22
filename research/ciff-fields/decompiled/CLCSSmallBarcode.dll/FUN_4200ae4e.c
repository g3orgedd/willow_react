// Source: CLCSSmallBarcode.dll @ 4200ae4e; FUN_4200ae4e

short * __thiscall
FUN_4200ae4e(void *this,short *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  *(undefined4 *)((int)this + 0x40) = param_2;
  *(undefined4 *)((int)this + 0x44) = param_3;
  *(undefined4 *)((int)this + 0x48) = param_4;
  *(undefined4 *)((int)this + 0x4c) = param_5;
  *(undefined4 *)((int)this + 0x50) = param_6;
  *(undefined4 *)((int)this + 0x54) = param_7;
  *(undefined4 *)((int)this + 0x58) = param_8;
  *(undefined2 *)this = 0;
  if (param_1 != (short *)0x0) {
    FUN_4206a09b(this,0x20,param_1,0x1f);
    *(undefined2 *)((int)this + 0x3e) = 0;
  }
  *(int *)((int)this + 0x48) =
       (*(int *)((int)this + 0x58) / 2 + *(int *)((int)this + 0x54) * *(int *)((int)this + 0x48)) /
       *(int *)((int)this + 0x58);
  return this;
}


