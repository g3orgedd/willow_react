// Source: CLCSTextBasedField.dll @ 42467734; FUN_42467734

undefined4 __thiscall FUN_42467734(void *this,uint param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_42467b65(this,param_1);
  if (CONCAT31(extraout_var,bVar1) == -1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)((int)this + (param_1 % 10) * 4 + 4);
  }
  return uVar2;
}


