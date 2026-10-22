// Source: CLCSSmallBarcode.dll @ 42027631; FUN_42027631

undefined4 __thiscall FUN_42027631(void *this,HGDIOBJ param_1,undefined4 param_2,HDC param_3)

{
  HGDIOBJ ho;
  
  if (*(int *)((int)this + 0x78) != 0) {
    ho = SelectObject(param_3,*(HGDIOBJ *)((int)this + 0x78));
    *(undefined4 *)((int)this + 0x78) = 0;
    if (ho == param_1) {
      DeleteObject(ho);
    }
  }
  DeleteDC(param_3);
  return 0;
}


