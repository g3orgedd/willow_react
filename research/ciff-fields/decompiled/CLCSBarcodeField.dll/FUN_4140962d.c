// Source: CLCSBarcodeField.dll @ 4140962d; FUN_4140962d

undefined4 * __thiscall FUN_4140962d(void *this,uint param_1,byte param_2)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  
  if (-*(int *)((int)this + 0x10) - 1U <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_4145ff05("string too long");
  }
  if (param_1 != 0) {
    uVar1 = *(int *)((int)this + 0x10) + param_1;
    bVar2 = FUN_414060f2(this,uVar1,'\0');
    if (bVar2) {
      FUN_414095eb(this,*(int *)((int)this + 0x10),param_1,param_2);
      *(uint *)((int)this + 0x10) = uVar1;
      pvVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        pvVar3 = *(void **)this;
      }
      *(undefined1 *)((int)pvVar3 + uVar1) = 0;
    }
  }
  return this;
}


