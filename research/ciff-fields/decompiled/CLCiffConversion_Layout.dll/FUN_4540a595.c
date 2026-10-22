// Source: CLCiffConversion_Layout.dll @ 4540a595; FUN_4540a595

undefined4 * __thiscall FUN_4540a595(void *this,uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar2 = FUN_4540ce07(this,param_1);
  if ((char)uVar2 != '\0') {
    param_1 = 0;
    FUN_4540a2b5(*(undefined4 **)this,uVar1,&param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + uVar1 * 4;
  }
  return this;
}


