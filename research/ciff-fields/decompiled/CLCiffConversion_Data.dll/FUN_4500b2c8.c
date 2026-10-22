// Source: CLCiffConversion_Data.dll @ 4500b2c8; FUN_4500b2c8

LPSTR FUN_4500b2c8(LPSTR param_1,LPCWSTR param_2,int param_3,UINT param_4)

{
  *param_1 = '\0';
  WideCharToMultiByte(param_4,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
  return param_1;
}


