// Source: CLCiffConversion_Data.dll @ 4501f875; FUN_4501f875

void __thiscall FUN_4501f875(void *this,undefined2 param_1)

{
  if (*(uint *)((int)this + 0xf0) < 0xe) {
    *(undefined2 *)((int)this + *(uint *)((int)this + 0xf0) * 2 + 0xd0) = param_1;
    *(int *)((int)this + 0xf0) = *(int *)((int)this + 0xf0) + 1;
    *(undefined2 *)((int)this + *(int *)((int)this + 0xf0) * 2 + 0xd0) = 0;
  }
  return;
}


