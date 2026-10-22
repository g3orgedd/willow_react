// Source: CLCiffConversion_Layout.dll @ 45421f7a; FUN_45421f7a

void __thiscall FUN_45421f7a(void *this,uint param_1)

{
  if (param_1 <= 0xccccccbU - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45429486("list<T> too long");
}


