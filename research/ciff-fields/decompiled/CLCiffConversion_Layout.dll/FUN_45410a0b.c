// Source: CLCiffConversion_Layout.dll @ 45410a0b; FUN_45410a0b

void __thiscall FUN_45410a0b(void *this,undefined2 param_1)

{
  if (*(uint *)((int)this + 0x14c) < 0x27) {
    *(undefined2 *)((int)this + *(uint *)((int)this + 0x14c) * 2 + 0xfc) = param_1;
    *(int *)((int)this + 0x14c) = *(int *)((int)this + 0x14c) + 1;
    *(undefined2 *)((int)this + *(int *)((int)this + 0x14c) * 2 + 0xfc) = 0;
  }
  return;
}


