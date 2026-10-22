// Source: CLCiffConversion_Layout.dll @ 45415381; FUN_45415381

undefined1 __cdecl FUN_45415381(LPCSTR param_1)

{
  LPCSTR pCVar1;
  UINT UVar2;
  
  if (DAT_45460782 == '\0') {
    pCVar1 = FUN_4540856d();
    UVar2 = GetPrivateProfileIntA("Debug","All",0,pCVar1);
    if (UVar2 == 0) {
      pCVar1 = FUN_4540856d();
      UVar2 = GetPrivateProfileIntA("Debug",param_1,0,pCVar1);
      DAT_45460781 = UVar2 != 0;
      DAT_45460782 = '\x01';
    }
    else {
      DAT_45460782 = '\x01';
      DAT_45460781 = 1;
    }
  }
  return DAT_45460781;
}


