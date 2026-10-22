// Source: CiffHelper.dll @ 40806c85; FUN_40806c85

undefined4 * __thiscall FUN_40806c85(void *this,uint param_1,uint param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  
  uVar2 = *(uint *)((int)this + 0x10);
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_4082cac3("invalid string position");
  }
  if (param_2 < uVar2 - param_1) {
    if (param_2 != 0) {
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar3 = *(void **)this;
      }
      puVar1 = (undefined8 *)((int)pvVar3 + param_1 * 2);
      iVar4 = uVar2 - param_2;
      FUN_40806d21(puVar1,(undefined8 *)((int)puVar1 + param_2 * 2),iVar4 - param_1);
      *(int *)((int)this + 0x10) = iVar4;
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar3 = *(void **)this;
      }
      *(undefined2 *)((int)pvVar3 + iVar4 * 2) = 0;
    }
  }
  else {
    *(uint *)((int)this + 0x10) = param_1;
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar3 = *(void **)this;
    }
    *(undefined2 *)((int)pvVar3 + param_1 * 2) = 0;
  }
  return this;
}


