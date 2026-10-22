// Source: CLCiffConversion_Data.dll @ 45007b2e; FUN_45007b2e

uint __thiscall FUN_45007b2e(void *this,uint param_1,uint param_2,wchar_t *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 <= *(uint *)((int)this + 0x10)) {
    uVar1 = *(uint *)((int)this + 0x10) - param_1;
    if (uVar1 < param_2) {
      param_2 = uVar1;
    }
    if (7 < *(uint *)((int)this + 0x14)) {
      this = *(void **)this;
    }
    uVar1 = param_4;
    if (param_2 < param_4) {
      uVar1 = param_2;
    }
    if (uVar1 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = _wmemcmp((wchar_t *)((int)this + param_1 * 2),param_3,uVar1);
    }
    uVar2 = (uint)(param_2 != param_4);
    if (param_2 < param_4) {
      uVar2 = 0xffffffff;
    }
    if (uVar1 != 0) {
      uVar2 = uVar1;
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45020fe3("invalid string position");
}


