// Source: CLCiffConversion_Layout.dll @ 45413189; FUN_45413189

int __thiscall FUN_45413189(void *this,int *param_1)

{
  int *piVar1;
  
  if (*(int **)this != param_1) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    piVar1 = *(int **)this;
    *(int **)this = param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  return *(int *)this;
}


