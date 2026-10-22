// Source: CLCiffConversion_Layout.dll @ 454153ea; FUN_454153ea

undefined1 __cdecl FUN_454153ea(LPCSTR param_1)

{
  LPCSTR pCVar1;
  UINT UVar2;
  
  if (DAT_45460784 == '\0') {
    pCVar1 = FUN_4540856d();
    UVar2 = GetPrivateProfileIntA("DebugLog","All",0,pCVar1);
    if (UVar2 == 0) {
      pCVar1 = FUN_4540856d();
      UVar2 = GetPrivateProfileIntA("DebugLog",param_1,0,pCVar1);
      DAT_45460783 = UVar2 != 0;
      DAT_45460784 = '\x01';
    }
    else {
      DAT_45460784 = '\x01';
      DAT_45460783 = 1;
    }
  }
  return DAT_45460783;
}


