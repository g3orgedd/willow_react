// Source: CLARiSOFT.exe @ 00e06468; FUN_00e06468

bool __thiscall FUN_00e06468(void *this,uint param_1,char param_2)

{
  uint uVar1;
  
  if (param_1 != 0xffffffff) {
    if (*(uint *)((int)this + 0x14) < param_1) {
      FUN_00e06259(this,param_1);
    }
    else if ((param_2 == '\0') || (0xf < param_1)) {
      if (param_1 == 0) {
        *(undefined4 *)((int)this + 0x10) = 0;
        if (0xf < *(uint *)((int)this + 0x14)) {
          this = *(void **)this;
        }
        *(undefined1 *)this = 0;
      }
    }
    else {
      uVar1 = *(uint *)((int)this + 0x10);
      if (param_1 < *(uint *)((int)this + 0x10)) {
        uVar1 = param_1;
      }
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(this,true,uVar1);
    }
    return param_1 != 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00ec8e92("string too long");
}


