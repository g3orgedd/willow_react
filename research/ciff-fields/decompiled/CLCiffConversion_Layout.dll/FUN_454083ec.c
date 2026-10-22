// Source: CLCiffConversion_Layout.dll @ 454083ec; FUN_454083ec

void __cdecl FUN_454083ec(void *param_1)

{
  LPCSTR lpFileName;
  CHAR local_10c [260];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_4540856d();
  GetPrivateProfileStringA("Generic","Installation Location","",local_10c,0x104,lpFileName);
  FUN_45402a65(param_1,local_10c);
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


