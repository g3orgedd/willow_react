// Source: CLCiffConversion_Layout.dll @ 4541b899; FUN_4541b899

int __thiscall FUN_4541b899(void *this,undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = *(int *)this;
  if (*(int *)((int)this + 4) - iVar1 >> 2 != 0) {
    do {
      iVar1 = FUN_4541b7e2(*(void **)(iVar1 + uVar2 * 4),param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
      iVar1 = *(int *)this;
    } while (uVar2 < (uint)(*(int *)((int)this + 4) - iVar1 >> 2));
  }
  return 0;
}


