// Source: CiffHelper.dll @ 40823bad; FUN_40823bad

void __cdecl FUN_40823bad(void *param_1)

{
  bool bVar1;
  undefined **ppuVar2;
  
  bVar1 = false;
  ppuVar2 = &PTR_u_VJ_Comet_408620e0;
  do {
    if (bVar1 != false) {
      return;
    }
    bVar1 = FUN_40803ed6(param_1,(OLECHAR *)*ppuVar2);
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x40862124);
  return;
}


