// Source: CLCiffConversion_Layout.dll @ 45401e75; FUN_45401e75

void __fastcall FUN_45401e75(int param_1)

{
  SelectClipRgn(*(HDC *)(param_1 + 8),*(HRGN *)(param_1 + 0xc));
  if (*(int *)(param_1 + 0xc) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


