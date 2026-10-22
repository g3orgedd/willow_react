// Source: CiffHelper.dll @ 40803825; FUN_40803825

undefined4 __cdecl FUN_40803825(int *param_1,int param_2,uint param_3)

{
  if (-param_2 - 1U < param_3) {
    return 0x80070216;
  }
  *param_1 = param_2 + param_3;
  return 0;
}


