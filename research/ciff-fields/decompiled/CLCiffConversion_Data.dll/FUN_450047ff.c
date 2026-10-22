// Source: CLCiffConversion_Data.dll @ 450047ff; FUN_450047ff

basic_string<char,std::char_traits<char>,std::allocator<char>_> * __thiscall
FUN_450047ff(void *this,char *param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  void *pvVar3;
  
  bVar2 = std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Inside
                    (this,param_1);
  if (bVar2) {
    pvVar3 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
      pvVar3 = *(void **)this;
    }
    this = FUN_45004759(this,this,(int)param_1 - (int)pvVar3,param_2);
  }
  else {
    if (-*(int *)((int)this + 0x10) - 1U <= param_2) {
                    /* WARNING: Subroutine does not return */
      FUN_45020fb5("string too long");
    }
    if (param_2 != 0) {
      uVar1 = *(int *)((int)this + 0x10) + param_2;
      bVar2 = FUN_4500452b(this,uVar1,'\0');
      if (bVar2) {
        pvVar3 = this;
        if (0xf < *(uint *)((int)this + 0x14)) {
          pvVar3 = *(void **)this;
        }
        if (param_2 != 0) {
          FUN_45021540((undefined8 *)(*(int *)((int)this + 0x10) + (int)pvVar3),
                       (undefined8 *)param_1,param_2);
        }
        *(uint *)((int)this + 0x10) = uVar1;
        pvVar3 = this;
        if (0xf < *(uint *)((int)this + 0x14)) {
          pvVar3 = *(void **)this;
        }
        *(undefined1 *)((int)pvVar3 + uVar1) = 0;
      }
    }
  }
  return this;
}


