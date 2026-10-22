// Source: CLCiffConversion_Layout.dll @ 45407be9; FUN_45407be9

void __cdecl FUN_45407be9(undefined4 *param_1)

{
  LSTATUS LVar1;
  size_t sVar2;
  DWORD local_74;
  HKEY local_70;
  BYTE local_6c;
  uint local_6b [24];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_6c = '\0';
  FUN_45429f70(local_6b,0,99);
  _strcpy_s((char *)&local_6c,100,(char *)*param_1);
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,"Software\\Claricom Ltd\\LanguageName",0,(LPSTR)0x0,0,
                          0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_70,&local_74);
  if (LVar1 == 0) {
    sVar2 = _strlen((char *)&local_6c);
    RegSetValueExA(local_70,"LanguageName",0,1,&local_6c,sVar2 + 1);
    RegCloseKey(local_70);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


