// Source: CLCiffConversion_Layout.dll @ 454089b0; FUN_454089b0

void __fastcall FUN_454089b0(int param_1)

{
  if (*(int *)(param_1 + 4) != -1) {
    FindClose(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  return;
}


