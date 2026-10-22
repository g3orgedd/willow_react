// Source: CLCiffConversion_Data.dll @ 4500b3b7; FUN_4500b3b7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_4500b3b7(undefined4 *param_1)

{
  bool bVar1;
  LPCWSTR lpFileName;
  undefined3 extraout_var;
  int *piVar2;
  int local_224;
  LPCWSTR local_220;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_220 = (LPCWSTR)PTR_DAT_4505101c;
  local_8 = 1;
  FUN_450037ea(&local_220,L"%s_%02d");
  lpFileName = FUN_4501ca38();
  GetPrivateProfileStringW(L"Generic",local_220,L"",local_21c,0x104,lpFileName);
  FUN_450020a5(param_1,local_21c);
  bVar1 = FUN_450034f4((LPCWSTR)*param_1,(ushort *)L"Table containing Index Fields");
  if (CONCAT31(extraout_var,bVar1) != 0) {
    piVar2 = FUN_4501cb23(&local_224,0x64cc);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_45008a06(param_1,piVar2);
    FUN_45002256(&local_224);
  }
  FUN_45002256((int *)&local_220);
  FUN_45022eb8();
  return;
}


