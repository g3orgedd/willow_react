// Source: CLCiffConversion_Layout.dll @ 45410f62; FUN_45410f62

undefined4 __thiscall FUN_45410f62(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  WCHAR WVar3;
  
  WVar3 = (WCHAR)param_1;
  if (WVar3 == L'}') {
    FUN_454109d7(this,0x7d);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    uVar1 = FUN_45411df8((int)this);
  }
  else {
    iVar2 = FUN_4542d066(WVar3);
    if (((iVar2 == 0) && (WVar3 != L'.')) && (WVar3 != L'-')) {
      uVar1 = FUN_45411df8((int)this);
      *(undefined4 *)((int)this + 0xa8) = uVar1;
      FUN_45411e13(this,param_1,0);
      uVar1 = *(undefined4 *)((int)this + 0xa8);
    }
    else {
      FUN_45410a0b(this,WVar3);
      uVar1 = 5;
    }
  }
  return uVar1;
}


