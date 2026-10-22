// Source: CLARiSOFT.exe @ 00e065d5; FUN_00e065d5

void FUN_00e065d5(UINT param_1,LPWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = LoadStringW(DAT_00f44270,param_1,param_2,param_3);
  if (iVar1 == 0) {
    *param_2 = L'\0';
  }
  return;
}


