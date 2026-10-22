// Source: CLCiffConversion_Layout.dll @ 454110a3; FUN_454110a3

undefined4 __thiscall FUN_454110a3(void *this,wchar_t param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == L'\'') {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_45410fd0((wchar_t *)((int)this + 0xc),param_1);
    if (iVar2 == -1) {
      FUN_45410a3f(this,param_1);
      uVar1 = 0;
    }
    else {
      *(wchar_t *)((int)this + 0xd0) = param_1;
      *(undefined2 *)((int)this + 0xd2) = 0;
      *(undefined4 *)((int)this + 0xf0) = 1;
      *(undefined4 *)((int)this + 0xf8) = 1;
      *(wchar_t *)((int)this + 0xf4) = param_1;
      uVar1 = 3;
    }
  }
  return uVar1;
}


