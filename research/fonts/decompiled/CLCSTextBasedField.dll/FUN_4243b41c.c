// Source: CLCSTextBasedField.dll @ 4243b41c; FUN_4243b41c

void __fastcall FUN_4243b41c(int param_1)

{
  HGDIOBJ ho;
  
  if ((*(int *)(param_1 + 0xb4) != 0) && (*(HGDIOBJ *)(param_1 + 0xb8) != (HGDIOBJ)0x0)) {
    ho = SelectObject(*(HDC *)(param_1 + 8),*(HGDIOBJ *)(param_1 + 0xb8));
    DeleteObject(ho);
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  return;
}


