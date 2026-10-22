// Source: CLCSGraphicBasedField.dll @ 41c0168b; FUN_41c0168b

int __thiscall FUN_41c0168b(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_1;
  if (*(int **)this != piVar1) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    piVar2 = *(int **)this;
    *(int **)this = piVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  return *(int *)this;
}


