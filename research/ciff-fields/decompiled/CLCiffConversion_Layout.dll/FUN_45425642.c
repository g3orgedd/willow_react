// Source: CLCiffConversion_Layout.dll @ 45425642; FUN_45425642

undefined4 FUN_45425642(LPCSTR param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR_s_AppID_45447d1c;
  do {
    iVar1 = lstrcmpiA(param_1,*ppuVar2);
    if (iVar1 == 0) {
      return 0;
    }
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x45447d4c);
  return 1;
}


