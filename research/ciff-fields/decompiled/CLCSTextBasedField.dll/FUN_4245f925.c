// Source: CLCSTextBasedField.dll @ 4245f925; FUN_4245f925

undefined4 * __thiscall FUN_4245f925(void *this,uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar2 = FUN_424621d4(this,param_1);
  if ((char)uVar2 != '\0') {
    param_1 = 0;
    FUN_4245f640(*(undefined2 **)this,uVar1,(undefined2 *)&param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + uVar1 * 2;
  }
  return this;
}


