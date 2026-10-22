// Source: CLCiffConversion_Layout.dll @ 4540ddf0; FUN_4540ddf0

undefined4 __thiscall FUN_4540ddf0(void *this,uint param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_4540e255(this,param_1);
  if (CONCAT31(extraout_var,bVar1) == -1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)((int)this + (param_1 % 10) * 4 + 4);
  }
  return uVar2;
}


