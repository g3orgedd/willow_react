// Source: CLCiffConversion_Data.dll @ 4501fe00; FUN_4501fe00

undefined4 __thiscall FUN_4501fe00(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  WCHAR WVar3;
  
  WVar3 = (WCHAR)param_1;
  if (WVar3 == L'}') {
    FUN_4501f875(this,0x7d);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    uVar1 = FUN_4502086a((int)this);
  }
  else {
    iVar2 = FUN_45021517(WVar3);
    if (((iVar2 == 0) && (WVar3 != L'.')) && (WVar3 != L'-')) {
      uVar1 = FUN_4502086a((int)this);
      *(undefined4 *)((int)this + 0xa8) = uVar1;
      FUN_45020885(this,param_1,0);
      uVar1 = *(undefined4 *)((int)this + 0xa8);
    }
    else {
      FUN_4501f8a9(this,WVar3);
      uVar1 = 5;
    }
  }
  return uVar1;
}


