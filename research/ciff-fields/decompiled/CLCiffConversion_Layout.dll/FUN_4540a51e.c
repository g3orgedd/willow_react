// Source: CLCiffConversion_Layout.dll @ 4540a51e; FUN_4540a51e

undefined4 * __thiscall FUN_4540a51e(void *this,uint param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_4540ce9d(this,param_1);
  if ((char)uVar1 != '\0') {
    FUN_45429f70(*(uint **)this,0,param_1);
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
  }
  return this;
}


