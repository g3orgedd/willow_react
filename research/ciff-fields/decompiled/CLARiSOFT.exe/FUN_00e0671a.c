// Source: CLARiSOFT.exe @ 00e0671a; FUN_00e0671a

int __cdecl FUN_00e0671a(LPWSTR param_1,LPCSTR param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 == 0) && (param_1 != (LPWSTR)0x0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = MultiByteToWideChar(0,0,param_2,-1,param_1,param_3);
    if ((param_1 != (LPWSTR)0x0) && (0 < iVar1)) {
      param_1[iVar1 + -1] = L'\0';
    }
  }
  return iVar1;
}


