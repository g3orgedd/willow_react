// Source: CLCSSmallBarcode.dll @ 4202a25a; FUN_4202a25a

undefined4 __thiscall FUN_4202a25a(void *this,HDC param_1)

{
  HGDIOBJ ho;
  
  if (*(HGDIOBJ *)((int)this + 0xb8) != (HGDIOBJ)0x0) {
    ho = SelectObject(param_1,*(HGDIOBJ *)((int)this + 0xb8));
    DeleteObject(ho);
    *(undefined4 *)((int)this + 0xb8) = 0;
  }
  return 0;
}


