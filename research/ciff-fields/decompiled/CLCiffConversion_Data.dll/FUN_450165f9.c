// Source: CLCiffConversion_Data.dll @ 450165f9; FUN_450165f9

int __thiscall FUN_450165f9(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
      iVar1 = lstrcmpiW(*(LPCWSTR *)(*(int *)this + iVar2 * 4),(LPCWSTR)*param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  return -1;
}


