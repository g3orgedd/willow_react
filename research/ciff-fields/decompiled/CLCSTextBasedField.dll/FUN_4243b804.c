// Source: CLCSTextBasedField.dll @ 4243b804; FUN_4243b804

void __fastcall FUN_4243b804(int param_1)

{
  HRGN hrgn;
  int iVar1;
  
  hrgn = CreateRectRgn(0,0,0,0);
  *(HRGN *)(param_1 + 0xc) = hrgn;
  iVar1 = GetClipRgn(*(HDC *)(param_1 + 8),hrgn);
  if (iVar1 != 1) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  IntersectClipRect(*(HDC *)(param_1 + 8),*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x24),
                    *(int *)(param_1 + 0x28),*(int *)(param_1 + 0x2c));
  return;
}


