// Source: CiffMgr.dll @ 68112177; FUN_68112177

undefined4 FUN_68112177(int param_1,uint param_2)

{
  int *this;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  _union_2683 local_1c;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  uVar1 = 0;
  if (param_2 != 0) {
    SysFreeString((BSTR)0x0);
    uVar1 = param_2;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  uVar1 = FUN_68112452((void *)(param_1 + 0x98),uVar1);
  if (uVar1 == 0xffffffff) {
    local_8 = 0x80070057;
  }
  else {
    this = (int *)(param_1 + 4);
    param_2 = *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8);
    iVar4 = param_2 * 0x10;
    local_1c.n2.vt = 0;
    FUN_68104449(&local_1c,(VARIANTARG *)(*this + iVar4));
    FUN_68104800(this,&local_c,(VARIANTARG *)(*this + iVar4));
    FUN_6810583c(this,&local_c,(VARIANTARG *)*this,1,(VARIANTARG *)&local_1c.n2);
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
      if (uVar2 < param_2) {
        *(uint *)(*(int *)(param_1 + 0x9c) + 4 + uVar3 * 8) = uVar2 + 1;
      }
      uVar3 = uVar3 + 1;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x9c) + 4 + uVar1 * 8) = 0;
    VariantClear((VARIANTARG *)&local_1c.n2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  param_2 = 0;
  FUN_6811115c((int *)&param_2);
  return local_8;
}


