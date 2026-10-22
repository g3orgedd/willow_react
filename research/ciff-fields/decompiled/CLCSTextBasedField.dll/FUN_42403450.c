// Source: CLCSTextBasedField.dll @ 42403450; FUN_42403450

undefined4 __cdecl FUN_42403450(int *param_1,int param_2,uint param_3)

{
  if (-param_2 - 1U < param_3) {
    return 0x80070216;
  }
  *param_1 = param_2 + param_3;
  return 0;
}


