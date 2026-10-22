// Source: CiffMgr.dll @ 6811206a; FUN_6811206a

undefined4 FUN_6811206a(int param_1,uint param_2)

{
  int *this;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  _union_2683 local_18;
  undefined4 local_8;
  
  uVar4 = 0;
  uVar1 = 0;
  if (param_2 != 0) {
    SysFreeString((BSTR)0x0);
    uVar1 = param_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  uVar1 = FUN_68112452((void *)(param_1 + 0x98),uVar1);
  if (uVar1 == 0xffffffff) {
    uVar4 = 0x80070057;
  }
  else {
    param_2 = *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8);
    iVar5 = param_2 * 0x10;
    local_18.n2.vt = 0;
    FUN_68104449(&local_18,(VARIANTARG *)(*(int *)(param_1 + 4) + iVar5));
    this = (int *)(param_1 + 4);
    FUN_68104800(this,&local_8,(VARIANTARG *)(*(int *)(param_1 + 4) + iVar5));
    FUN_68104866(this,(VARIANTARG *)&local_18.n2);
    uVar3 = (*(int *)(param_1 + 0xa4) != 0) - 1;
    while( true ) {
      if (*(int *)(param_1 + 0xa4) == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(int *)(param_1 + 0xa4) - 1;
      }
      if (uVar2 < uVar3) break;
      uVar2 = *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar3 * 8);
      if (param_2 < uVar2) {
        *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar3 * 8) = uVar2 - 1;
      }
      uVar3 = uVar3 + 1;
    }
    *(int *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8) = (*(int *)(param_1 + 8) - *this >> 4) + -1;
    VariantClear((VARIANTARG *)&local_18.n2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  param_2 = 0;
  FUN_6811115c((int *)&param_2);
  return uVar4;
}


