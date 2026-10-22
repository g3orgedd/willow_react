// Source: CLCiffConversion_Layout.dll @ 45421dd2; FUN_45421dd2

/* WARNING: Variable defined which should be unmapped: param_2 */

int __thiscall FUN_45421dd2(void *param_1,int param_2,char param_3,void *param_4)

{
  void *local_8;
  
  local_8 = param_1;
  (**(code **)(**(int **)((int)param_1 + 0x34) + 0x54))(*(int **)((int)param_1 + 0x34),&local_8);
  if (local_8 != param_4) {
    if (local_8 == (void *)0x0) {
      if (param_4 == (void *)0x1) {
        FUN_45406cd5(param_1,param_2,param_3);
        return param_2;
      }
    }
    else if ((local_8 == (void *)0x1) && (param_4 == (void *)0x0)) {
      FUN_4541dc35(param_1,param_2,param_3);
      return param_2;
    }
    FUN_4540303d(0x454497e8);
  }
  return param_2;
}


