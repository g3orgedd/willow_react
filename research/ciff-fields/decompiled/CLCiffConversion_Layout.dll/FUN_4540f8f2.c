// Source: CLCiffConversion_Layout.dll @ 4540f8f2; FUN_4540f8f2

void FUN_4540f8f2(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    SysFreeString(*(BSTR *)(param_1 + 4));
  }
  return;
}


