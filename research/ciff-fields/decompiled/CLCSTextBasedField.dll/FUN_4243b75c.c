// Source: CLCSTextBasedField.dll @ 4243b75c; FUN_4243b75c

void __thiscall
FUN_4243b75c(void *this,short *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  *(undefined4 *)((int)this + 0x5c) = param_5;
  *(undefined1 *)((int)this + 0x67) = param_2;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  *(undefined4 *)((int)this + 0x60) = 0x1000000;
  *(undefined2 *)((int)this + 100) = 7;
  *(undefined1 *)((int)this + 0x66) = 1;
  FUN_4246f507((short *)((int)this + 0x68),0x20,param_1,0x1f);
  *(undefined2 *)((int)this + 0xa6) = 0;
  *(undefined4 *)((int)this + 0xa8) = param_4;
  *(undefined4 *)((int)this + 0xac) = param_3;
  *(undefined4 *)((int)this + 0xb0) = 1;
  *(undefined4 *)((int)this + 0xcc) = param_6;
  return;
}


