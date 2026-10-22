// Source: CLCSTextBasedField.dll @ 42420b25; FUN_42420b25

undefined4 * __thiscall FUN_42420b25(void *this,int *param_1)

{
  *(undefined4 *)this = 0;
  FUN_42420daa(this,(int *)&param_1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return this;
}


