// Source: CLCiffConversion_Data.dll @ 4500b102; FUN_4500b102

LPWSTR FUN_4500b102(LPWSTR param_1,LPCSTR param_2,int param_3,UINT param_4)

{
  *param_1 = L'\0';
  MultiByteToWideChar(param_4,0,param_2,-1,param_1,param_3);
  return param_1;
}


