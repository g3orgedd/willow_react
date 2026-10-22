// Source: CiffMgr.dll @ 681157f4; FUN_681157f4

undefined4 __thiscall FUN_681157f4(void *this,int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_1 = *(int *)this;
    piVar1 = *(int **)this;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


