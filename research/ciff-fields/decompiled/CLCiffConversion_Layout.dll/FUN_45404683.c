// Source: CLCiffConversion_Layout.dll @ 45404683; FUN_45404683

int __cdecl FUN_45404683(LPSTR param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 == 0) && (param_1 != (LPSTR)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = WideCharToMultiByte(0,0,param_2,-1,param_1,param_3,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((param_1 != (LPSTR)0x0) && (0 < iVar1)) {
      param_1[iVar1 + -1] = '\0';
    }
  }
  return iVar1;
}


