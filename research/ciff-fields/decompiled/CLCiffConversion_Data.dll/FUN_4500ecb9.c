// Source: CLCiffConversion_Data.dll @ 4500ecb9; FUN_4500ecb9

int __thiscall FUN_4500ecb9(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  iVar2 = *(int *)(*(int *)this + -8);
  if ((0 < param_2) && (param_1 < iVar2)) {
    if (iVar2 < param_1 + param_2) {
      param_2 = iVar2 - param_1;
    }
    FUN_4500363c(this);
    iVar1 = *(int *)this;
    FUN_45014375((void *)(iVar1 + param_1 * 2),(*(int *)(iVar1 + -4) - param_1) * 2 + 2,
                 (void *)(iVar1 + (param_1 + param_2) * 2),(((iVar2 - param_1) - param_2) + 1) * 2);
    iVar2 = iVar2 - param_2;
    *(int *)(*(int *)this + -8) = iVar2;
  }
  return iVar2;
}


