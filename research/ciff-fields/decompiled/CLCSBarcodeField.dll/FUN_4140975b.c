// Source: CLCSBarcodeField.dll @ 4140975b; FUN_4140975b

undefined4 * __thiscall FUN_4140975b(void *this,undefined8 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  
  uVar2 = FID_conflict__Inside(this,(undefined4 *)param_1);
  if ((char)uVar2 == '\0') {
    if (-*(int *)((int)this + 0x10) - 1U <= param_2) {
                    /* WARNING: Subroutine does not return */
      FUN_4145ff05("string too long");
    }
    if (param_2 != 0) {
      uVar2 = *(int *)((int)this + 0x10) + param_2;
      bVar1 = FUN_41406155(this,uVar2,'\0');
      if (bVar1) {
        pvVar3 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar3 = *(void **)this;
        }
        copy((undefined8 *)((int)pvVar3 + *(int *)((int)this + 0x10) * 2),param_1,param_2);
        *(uint *)((int)this + 0x10) = uVar2;
        pvVar3 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar3 = *(void **)this;
        }
        *(undefined2 *)((int)pvVar3 + uVar2 * 2) = 0;
      }
    }
  }
  else {
    pvVar3 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar3 = *(void **)this;
    }
    this = FUN_4140968e(this,this,(int)param_1 - (int)pvVar3 >> 1,param_2);
  }
  return this;
}


