// Source: CiffMgr.dll @ 681091d8; FUN_681091d8

void __fastcall FUN_681091d8(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    uVar1 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        if (*(int *)(*(int *)(param_1 + 4) + uVar1 * 8) != 0) {
          SysFreeString(*(BSTR *)(*(int *)(param_1 + 4) + uVar1 * 8));
          *(undefined4 *)(*(int *)(param_1 + 4) + uVar1 * 8) = 0;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


