// Source: CLCSTextBasedField.dll @ 4245f8ee; FUN_4245f8ee

undefined4 * __thiscall FUN_4245f8ee(void *this,uint param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_4246218d(this,param_1);
  if ((char)uVar1 != '\0') {
    FUN_4246d990(*(uint **)this,0,param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
  }
  return this;
}


