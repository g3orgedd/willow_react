// Source: CLCiffConversion_Layout.dll @ 454109d7; FUN_454109d7

void __thiscall FUN_454109d7(void *this,undefined2 param_1)

{
  if (*(uint *)((int)this + 0xf0) < 0xe) {
    *(undefined2 *)((int)this + *(uint *)((int)this + 0xf0) * 2 + 0xd0) = param_1;
    *(int *)((int)this + 0xf0) = *(int *)((int)this + 0xf0) + 1;
    *(undefined2 *)((int)this + *(int *)((int)this + 0xf0) * 2 + 0xd0) = 0;
  }
  return;
}


