// Source: CLCiffConversion_Layout.dll @ 45401f58; FUN_45401f58

void __fastcall FUN_45401f58(int param_1)

{
  HGDIOBJ ho;
  
  if ((*(int *)(param_1 + 0x94) != 0) && (*(HGDIOBJ *)(param_1 + 0x98) != (HGDIOBJ)0x0)) {
    ho = SelectObject(*(HDC *)(param_1 + 8),*(HGDIOBJ *)(param_1 + 0x98));
    DeleteObject(ho);
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  return;
}


