// Source: CiffHelper.dll @ 4080e9e6; FUN_4080e9e6

undefined4 * __thiscall FUN_4080e9e6(void *this,uint param_1,uint param_2,wchar_t param_3)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  void *pvVar4;
  
  uVar1 = *(uint *)((int)this + 0x10);
  if (uVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_4082cac3("invalid string position");
  }
  if (-uVar1 - 1 <= param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_4082ca95("string too long");
  }
  if (param_2 != 0) {
    uVar1 = uVar1 + param_2;
    bVar2 = FUN_4080641a(this,uVar1,'\0');
    if (bVar2) {
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar3 = *(void **)this;
      }
      pvVar4 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar4 = *(void **)this;
      }
      FUN_40806d21((undefined8 *)((int)pvVar4 + (param_1 + param_2) * 2),
                   (undefined8 *)((int)pvVar3 + param_1 * 2),*(int *)((int)this + 0x10) - param_1);
      FID_conflict__Chassign(this,param_1,param_2,param_3);
      *(uint *)((int)this + 0x10) = uVar1;
      pvVar3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar3 = *(void **)this;
      }
      *(undefined2 *)((int)pvVar3 + uVar1 * 2) = 0;
    }
  }
  return this;
}


