// Source: CLCiffConversion_Data.dll @ 450177f5; FUN_450177f5

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_450177f5(LPCWSTR param_1,LPCWSTR param_2,LPCWSTR param_3)

{
  HMODULE hModule;
  HRSRC hResInfo;
  HGLOBAL pvVar1;
  DWORD DVar2;
  undefined1 *local_41c;
  undefined1 auStack_418 [1040];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x424;
  local_41c = (undefined1 *)0x0;
  local_8 = 1;
  hModule = LoadLibraryExW(param_1,(HANDLE)0x0,0x60);
  if ((hModule == (HMODULE)0x0) &&
     (hModule = LoadLibraryExW(param_1,(HANDLE)0x0,2), hModule == (HMODULE)0x0)) {
    FUN_450155e4();
  }
  else {
    hResInfo = FindResourceW(hModule,param_2,param_3);
    if ((hResInfo == (HRSRC)0x0) ||
       (pvVar1 = LoadResource(hModule,hResInfo), pvVar1 == (HGLOBAL)0x0)) {
      FUN_450155e4();
    }
    else {
      DVar2 = SizeofResource(hModule,hResInfo);
      if (DVar2 <= DVar2 + 1) {
        local_8 = CONCAT31(local_8._1_3_,2);
        Allocate(&local_41c,DVar2 + 1);
        FUN_450178eb();
        return;
      }
    }
    if (hModule != (HMODULE)0x0) {
      FreeLibrary(hModule);
    }
  }
  if (local_41c != auStack_418) {
    FUN_45016630(&local_41c);
  }
  FUN_45022ec7();
  return;
}


