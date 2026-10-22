// Source: CLCiffConversion_Data.dll @ 45015ed2; FUN_45015ed2

undefined4 FUN_45015ed2(LPCWSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_u_AppID_4503ddfc;
  do {
    iVar1 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x4503de2c);
  return 1;
}


