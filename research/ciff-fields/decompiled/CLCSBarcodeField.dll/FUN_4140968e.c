// Source: CLCSBarcodeField.dll @ 4140968e; FUN_4140968e

undefined4 * __thiscall FUN_4140968e(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  
  if ((uint)param_1[4] < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_4145ff33("invalid string position");
  }
  uVar3 = param_1[4] - param_2;
  iVar1 = *(int *)((int)this + 0x10);
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (-iVar1 - 1U <= param_3) {
                    /* WARNING: Subroutine does not return */
    FUN_4145ff05("string too long");
  }
  if ((param_3 != 0) && (bVar2 = FUN_41406155(this,iVar1 + param_3,'\0'), bVar2)) {
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar4 = *(void **)this;
    }
    copy((undefined8 *)((int)pvVar4 + *(int *)((int)this + 0x10) * 2),
         (undefined8 *)((int)param_1 + param_2 * 2),param_3);
    *(uint *)((int)this + 0x10) = iVar1 + param_3;
    pvVar4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar4 = *(void **)this;
    }
    *(undefined2 *)((int)pvVar4 + (iVar1 + param_3) * 2) = 0;
  }
  return this;
}


