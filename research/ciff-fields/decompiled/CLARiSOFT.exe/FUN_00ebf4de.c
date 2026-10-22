// Source: CLARiSOFT.exe @ 00ebf4de; FUN_00ebf4de

void __thiscall FUN_00ebf4de(void *this,uint param_1)

{
  if (param_1 <= 0x15555554U - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00ec8e92("list<T> too long");
}


