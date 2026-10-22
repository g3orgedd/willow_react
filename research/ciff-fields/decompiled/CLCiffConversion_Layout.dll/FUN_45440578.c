// Source: CLCiffConversion_Layout.dll @ 45440578; FUN_45440578

undefined4 FUN_45440578(void)

{
  uint cbMultiByte;
  int iVar1;
  undefined4 *puVar2;
  LPSTR local_8;
  
  local_8 = (LPSTR)0x0;
  puVar2 = DAT_45460bb4;
  while( true ) {
    if ((LPCWSTR)*puVar2 == (LPCWSTR)0x0) {
      return 0;
    }
    cbMultiByte = WideCharToMultiByte(0,0,(LPCWSTR)*puVar2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((cbMultiByte == 0) || (local_8 = FUN_454375c4(cbMultiByte,1), local_8 == (LPSTR)0x0)) break;
    iVar1 = WideCharToMultiByte(0,0,(LPCWSTR)*puVar2,-1,local_8,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0)
    ;
    if (iVar1 == 0) {
      FID_conflict__free(local_8);
      return 0xffffffff;
    }
    iVar1 = FUN_4544135c(&local_8,0);
    if ((iVar1 < 0) && (local_8 != (LPSTR)0x0)) {
      FID_conflict__free(local_8);
      local_8 = (LPSTR)0x0;
    }
    puVar2 = puVar2 + 1;
  }
  return 0xffffffff;
}


