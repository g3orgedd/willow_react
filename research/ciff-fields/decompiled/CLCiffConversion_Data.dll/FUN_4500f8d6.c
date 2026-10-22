// Source: CLCiffConversion_Data.dll @ 4500f8d6; FUN_4500f8d6

undefined4 __thiscall FUN_4500f8d6(void *this,void *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)((int)this + 0x20);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    uVar1 = FUN_4500f908(piVar2,param_1);
  }
  return uVar1;
}


