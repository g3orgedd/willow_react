// Source: CLCiffConversion_Data.dll @ 450141c8; FUN_450141c8

undefined4 * __thiscall FUN_450141c8(void *this,uint param_1,wchar_t param_2)

{
  bool bVar1;
  void *pvVar2;
  
  if (param_1 == 0xffffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fb5("string too long");
  }
  bVar1 = FUN_4500458e(this,param_1,'\0');
  if (bVar1) {
    FID_conflict__Chassign(this,0,param_1,param_2);
    *(uint *)((int)this + 0x10) = param_1;
    pvVar2 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar2 = *(void **)this;
    }
    *(undefined2 *)((int)pvVar2 + param_1 * 2) = 0;
  }
  return this;
}


