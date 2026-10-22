// Source: CLCiffConversion_Data.dll @ 4501fbf8; FUN_4501fbf8

undefined4 __thiscall FUN_4501fbf8(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t wVar3;
  
  wVar3 = (wchar_t)param_1;
  if (*(short *)((int)this + 0xf4) == 0) {
    if (wVar3 == L':') {
      FUN_4501f875(this,0x3a);
      return 4;
    }
    iVar1 = FUN_4501fe6e((wchar_t *)((int)this + 0x3e),wVar3);
    if (iVar1 == -1) {
      FUN_4501f984(this,(wchar_t *)((int)this + 0xd0));
      return 0;
    }
    *(wchar_t *)((int)this + 0xf4) = wVar3;
  }
  if (wVar3 == *(wchar_t *)((int)this + 0xf4)) {
    FUN_4501f875(this,wVar3);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    return 4;
  }
  if (wVar3 == L'c') {
    iVar1 = FUN_4501fe6e((wchar_t *)((int)this + 0x70),*(wchar_t *)((int)this + 0xf4));
    if (iVar1 != -1) {
      FUN_4501f875(this,99);
      uVar2 = FUN_4502086a((int)this);
      *(undefined4 *)((int)this + 0xa8) = uVar2;
      return 0;
    }
  }
  else if (wVar3 == L'{') {
    FUN_4501f875(this,0x7b);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    *(undefined2 *)((int)this + 0xfc) = 0;
    *(undefined4 *)((int)this + 0x14c) = 0;
    return 5;
  }
  uVar2 = FUN_4502086a((int)this);
  *(undefined4 *)((int)this + 0xa8) = uVar2;
  FUN_45020885(this,param_1,0);
  return *(undefined4 *)((int)this + 0xa8);
}


