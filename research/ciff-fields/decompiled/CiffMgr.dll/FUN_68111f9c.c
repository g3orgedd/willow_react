// Source: CiffMgr.dll @ 68111f9c; FUN_68111f9c

undefined4 FUN_68111f9c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  uVar3 = 0;
  uVar1 = 0;
  if (param_2 != 0) {
    SysFreeString((BSTR)0x0);
    uVar1 = param_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  uVar1 = FUN_68112452((void *)(param_1 + 0x98),uVar1);
  if (uVar1 == 0xffffffff) {
    uVar3 = 0x80070057;
  }
  else {
    param_2 = *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8);
    FUN_681123fe((void *)(param_1 + 0x98),uVar1);
    FUN_68104800((int *)(param_1 + 4),&local_8,
                 (VARIANTARG *)(param_2 * 0x10 + *(int *)(param_1 + 4)));
    uVar1 = (*(int *)(param_1 + 0xa4) != 0) - 1;
    if (uVar1 != 0xffffffff) {
      while( true ) {
        if (*(int *)(param_1 + 0xa4) == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = *(int *)(param_1 + 0xa4) - 1;
        }
        if (uVar2 < uVar1) break;
        uVar2 = *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8);
        if (param_2 < uVar2) {
          *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8) = uVar2 - 1;
        }
        uVar1 = uVar1 + 1;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  param_2 = 0;
  FUN_6811115c((int *)&param_2);
  return uVar3;
}


