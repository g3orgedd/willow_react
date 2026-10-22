// Source: CLCiffConversion_Layout.dll @ 45425ca3; FUN_45425ca3

int __thiscall FUN_45425ca3(void *this,undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
      iVar1 = lstrcmpiA(*(LPCSTR *)(*(int *)this + iVar2 * 4),(LPCSTR)*param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  return -1;
}


