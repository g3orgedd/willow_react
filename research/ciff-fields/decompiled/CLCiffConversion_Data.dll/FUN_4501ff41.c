// Source: CLCiffConversion_Data.dll @ 4501ff41; FUN_4501ff41

undefined4 __thiscall FUN_4501ff41(void *this,wchar_t param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == L'\'') {
    uVar1 = 1;
  }
  else {
    iVar2 = FUN_4501fe6e((wchar_t *)((int)this + 0xc),param_1);
    if (iVar2 == -1) {
      FUN_4501f8dd(this,param_1);
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


