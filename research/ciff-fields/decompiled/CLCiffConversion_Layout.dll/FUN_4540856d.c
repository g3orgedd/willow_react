// Source: CLCiffConversion_Layout.dll @ 4540856d; FUN_4540856d

undefined1 * FUN_4540856d(void)

{
  char *_Src;
  
  if (DAT_454600f0 == '\0') {
    _Src = (char *)FUN_45408666();
    _strcpy_s(&DAT_454600f0,0x104,_Src);
    _strcat_s(&DAT_454600f0,0x104,"Claricom.INI");
  }
  return &DAT_454600f0;
}


