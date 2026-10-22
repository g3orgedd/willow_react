// Source: CLCiffConversion_Layout.dll @ 45402416; FUN_45402416

undefined4 * __thiscall FUN_45402416(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_454294b4("invalid string position");
  }
  if (param_2 < uVar1 - param_1) {
    if (param_2 != 0) {
      pvVar2 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        pvVar2 = *(void **)this;
      }
      iVar3 = uVar1 - param_2;
      if (iVar3 - param_1 != 0) {
        FUN_4542a090((undefined8 *)((int)pvVar2 + param_1),
                     (undefined8 *)((int)((int)pvVar2 + param_1) + param_2),iVar3 - param_1);
      }
      *(int *)((int)this + 0x10) = iVar3;
      pvVar2 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        pvVar2 = *(void **)this;
      }
      *(undefined1 *)((int)pvVar2 + iVar3) = 0;
    }
  }
  else {
    *(uint *)((int)this + 0x10) = param_1;
    pvVar2 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      pvVar2 = *(void **)this;
    }
    *(undefined1 *)((int)pvVar2 + param_1) = 0;
  }
  return this;
}


