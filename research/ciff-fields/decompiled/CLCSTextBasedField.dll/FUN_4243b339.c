// Source: CLCSTextBasedField.dll @ 4243b339; FUN_4243b339

void __fastcall FUN_4243b339(int param_1)

{
  SelectClipRgn(*(HDC *)(param_1 + 8),*(HRGN *)(param_1 + 0xc));
  if (*(int *)(param_1 + 0xc) != 0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


