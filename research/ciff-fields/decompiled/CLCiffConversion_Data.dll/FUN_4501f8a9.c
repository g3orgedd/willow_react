// Source: CLCiffConversion_Data.dll @ 4501f8a9; FUN_4501f8a9

void __thiscall FUN_4501f8a9(void *this,undefined2 param_1)

{
  if (*(uint *)((int)this + 0x14c) < 0x27) {
    *(undefined2 *)((int)this + *(uint *)((int)this + 0x14c) * 2 + 0xfc) = param_1;
    *(int *)((int)this + 0x14c) = *(int *)((int)this + 0x14c) + 1;
    *(undefined2 *)((int)this + *(int *)((int)this + 0x14c) * 2 + 0xfc) = 0;
  }
  return;
}


