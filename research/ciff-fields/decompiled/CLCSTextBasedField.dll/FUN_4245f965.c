// Source: CLCSTextBasedField.dll @ 4245f965; FUN_4245f965

undefined4 * __thiscall FUN_4245f965(void *this,uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar2 = FUN_4246221f(this,param_1);
  if ((char)uVar2 != '\0') {
    param_1 = 0;
    FUN_4245f662(*(undefined4 **)this,uVar1,&param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + uVar1 * 4;
  }
  return this;
}


