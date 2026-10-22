// Source: CLCSBarcodeField.dll @ 41409aec; FUN_41409aec

undefined4 __thiscall FUN_41409aec(void *this,HDC param_1)

{
  HGDIOBJ ho;
  
  if (*(int *)((int)this + 0x24) != 0) {
    ho = SelectObject(param_1,*(HGDIOBJ *)((int)this + 0x24));
    DeleteObject(ho);
    *(undefined4 *)((int)this + 0x24) = 0;
  }
  return 0;
}


