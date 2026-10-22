// Source: CLCSBarcodeField.dll @ 4144a22f; FUN_4144a22f

undefined4 __thiscall FUN_4144a22f(void *this,HDC param_1)

{
  HGDIOBJ ho;
  
  if (*(HGDIOBJ *)((int)this + 0xbc) != (HGDIOBJ)0x0) {
    ho = SelectObject(param_1,*(HGDIOBJ *)((int)this + 0xbc));
    DeleteObject(ho);
    *(undefined4 *)((int)this + 0xbc) = 0;
  }
  return 0;
}


