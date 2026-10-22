// Source: CLCSSmallBarcode.dll @ 42031972; FUN_42031972

undefined4 __thiscall FUN_42031972(void *this,undefined2 param_1)

{
  undefined4 uVar1;
  
  if (*(uint *)((int)this + 0x1214) < 0x3a0) {
    *(undefined2 *)((int)this + *(uint *)((int)this + 0x1214) * 2 + 0xad4) = param_1;
    *(int *)((int)this + 0x1214) = *(int *)((int)this + 0x1214) + 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x4022a;
  }
  return uVar1;
}


