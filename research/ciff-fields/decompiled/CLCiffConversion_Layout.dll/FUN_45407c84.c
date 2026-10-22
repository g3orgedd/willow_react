// Source: CLCiffConversion_Layout.dll @ 45407c84; FUN_45407c84

undefined4 __thiscall FUN_45407c84(void *this,undefined4 *param_1,void *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)((int)this + 0x18);
  uVar2 = 0x80004005;
  if (piVar1 == (int *)0x0) {
    FUN_45402c99(param_2,*(char **)this);
  }
  else {
    uVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,*param_1,param_2);
  }
  return uVar2;
}


