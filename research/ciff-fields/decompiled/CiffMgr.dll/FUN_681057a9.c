// Source: CiffMgr.dll @ 681057a9; FUN_681057a9

bool __thiscall FUN_681057a9(void *this,uint param_1,char param_2)

{
  uint uVar1;
  
  if (param_1 < 0x7fffffff) {
    if (*(uint *)((int)this + 0x14) < param_1) {
      FUN_6810569a(this,param_1);
    }
    else if ((param_2 == '\0') || (7 < param_1)) {
      if (param_1 == 0) {
        *(undefined4 *)((int)this + 0x10) = 0;
        if (7 < *(uint *)((int)this + 0x14)) {
          this = *(void **)this;
        }
        *(undefined2 *)this = 0;
      }
    }
    else {
      uVar1 = *(uint *)((int)this + 0x10);
      if (param_1 < *(uint *)((int)this + 0x10)) {
        uVar1 = param_1;
      }
      FUN_68105b16(this,'\x01',uVar1);
    }
    return param_1 != 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_68130e66("string too long");
}


