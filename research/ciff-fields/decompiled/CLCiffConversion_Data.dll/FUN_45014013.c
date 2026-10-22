// Source: CLCiffConversion_Data.dll @ 45014013; FUN_45014013

void FUN_45014013(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 8) {
    SysFreeString(*(BSTR *)(param_1 + 4));
  }
  return;
}


