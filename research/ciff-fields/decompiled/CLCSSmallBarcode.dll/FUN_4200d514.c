// Source: CLCSSmallBarcode.dll @ 4200d514; FUN_4200d514

void __fastcall FUN_4200d514(int param_1)

{
  if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    SelectObject(*(HDC *)(param_1 + 0xc),*(HGDIOBJ *)(param_1 + 0x14));
  }
  DeleteDC(*(HDC *)(param_1 + 0xc));
  if (*(int *)(param_1 + 0x10) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


