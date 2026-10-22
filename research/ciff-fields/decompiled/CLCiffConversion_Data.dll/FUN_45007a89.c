// Source: CLCiffConversion_Data.dll @ 45007a89; FUN_45007a89

undefined4 * __thiscall FUN_45007a89(void *this,uint param_1,wchar_t param_2)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  
  if (-*(int *)((int)this + 0x10) - 1U <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fb5("string too long");
  }
  if (param_1 != 0) {
    uVar1 = *(int *)((int)this + 0x10) + param_1;
    bVar2 = FUN_4500458e(this,uVar1,'\0');
    if (bVar2) {
      FID_conflict__Chassign(this,*(int *)((int)this + 0x10),param_1,param_2);
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


