// Source: CLCiffConversion_Data.dll @ 45016ad5; FUN_45016ad5

bool FUN_45016ad5(HKEY param_1)

{
  DWORD local_8;
  
  local_8 = 0;
  RegQueryInfoKeyW(param_1,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_8,(LPDWORD)0x0,(LPDWORD)0x0,
                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
  return local_8 != 0;
}


