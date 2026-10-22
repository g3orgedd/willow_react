// Source: CLCiffConversion_Data.dll @ 4500335a; FUN_4500335a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_4500335a(LPCWSTR param_1)

{
  LPCWSTR lpString;
  LPCWSTR lpFileName;
  undefined4 *puVar1;
  undefined4 uStackY_34;
  
  lpString = param_1;
  lpFileName = FUN_4501ca38();
  puVar1 = &uStackY_34;
  uStackY_34 = 0x45003384;
  WritePrivateProfileStringW(L"Generic",L"Start of Day",lpString,lpFileName);
  puVar1[-1] = 0x4500338c;
  FUN_45002256((int *)&param_1);
  puVar1[-1] = 0x45003391;
  return;
}


