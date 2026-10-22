// Source: CLARiSOFT.exe @ 00e4661c; FUN_00e4661c

undefined4 __cdecl FUN_00e4661c(void *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_00e03edc(param_1,L"VJ1550");
  if ((((!bVar1) && (bVar1 = FUN_00e03edc(param_1,L"VJ1650"), !bVar1)) &&
      (bVar1 = FUN_00e03edc(param_1,L"VJ1560"), !bVar1)) &&
     (((bVar1 = FUN_00e03edc(param_1,L"VJ1660"), !bVar1 &&
       (bVar1 = FUN_00e03edc(param_1,L"VJ1650 UHS"), !bVar1)) &&
      (bVar1 = FUN_00e03edc(param_1,L"VJ1650 HR"), !bVar1)))) {
    return 0;
  }
  return 1;
}


