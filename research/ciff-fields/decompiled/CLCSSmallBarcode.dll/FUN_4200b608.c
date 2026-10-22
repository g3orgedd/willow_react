// Source: CLCSSmallBarcode.dll @ 4200b608; FUN_4200b608

int __thiscall FUN_4200b608(void *this,LOGFONTW *param_1,undefined4 *param_2)

{
  HFONT ho;
  int iVar1;
  
  iVar1 = -1;
  ho = CreateFontIndirectW(param_1);
  if (ho != (HFONT)0x0) {
    iVar1 = FUN_4200b048(this,param_2);
    if (iVar1 == -1) {
      DeleteObject(ho);
    }
    else {
      *(HFONT *)(iVar1 * 0xd8 + 0xd0 + (int)this) = ho;
    }
  }
  return iVar1;
}


