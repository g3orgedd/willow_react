// Source: CLARiSOFT.exe @ 00e06754; FUN_00e06754

undefined4 * __thiscall FUN_00e06754(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_00ec8ec0("invalid string position");
  }
  uVar3 = param_1[4] - param_2;
  iVar1 = *(int *)((int)this + 0x10);
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (-iVar1 - 1U <= param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_00ec8e92("string too long");
  }
  if ((param_3 != 0) && (bVar2 = FUN_00e06468(this,iVar1 + param_3,'\0'), bVar2)) {
    if (0xf < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    pvVar4 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      pvVar4 = *(void **)this;
    }
    if (param_3 != 0) {
      FUN_00ecbd80((undefined8 *)(*(int *)((int)this + 0x10) + (int)pvVar4),
                   (undefined8 *)(param_2 + (int)param_1),param_3);
    }
    *(uint *)((int)this + 0x10) = iVar1 + param_3;
    pvVar4 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      pvVar4 = *(void **)this;
    }
    *(undefined1 *)((int)pvVar4 + iVar1 + param_3) = 0;
  }
  return this;
}


