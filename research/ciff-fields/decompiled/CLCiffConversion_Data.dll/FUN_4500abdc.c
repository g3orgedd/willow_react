// Source: CLCiffConversion_Data.dll @ 4500abdc; FUN_4500abdc

undefined2 * __thiscall FUN_4500abdc(void *this,int *param_1)

{
  *(undefined2 *)this = 9;
  *(int **)((int)this + 8) = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return this;
}


