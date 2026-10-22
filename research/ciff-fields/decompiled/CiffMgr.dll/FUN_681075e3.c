// Source: CiffMgr.dll @ 681075e3; FUN_681075e3

void __fastcall FUN_681075e3(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    SafeArrayDestroy(*(SAFEARRAY **)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}


