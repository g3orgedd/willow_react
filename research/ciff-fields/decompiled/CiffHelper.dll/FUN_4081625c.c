// Source: CiffHelper.dll @ 4081625c; FUN_4081625c

undefined4
FUN_4081625c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = FUN_4081bdba(param_2,param_3,param_4);
  if ((char)uVar1 == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}


