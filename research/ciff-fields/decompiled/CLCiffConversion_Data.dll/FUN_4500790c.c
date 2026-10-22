// Source: CLCiffConversion_Data.dll @ 4500790c; FUN_4500790c

void FUN_4500790c(void)

{
  int iVar1;
  
  iVar1 = _Allocate<>(1);
  if (iVar1 != 0) {
    *(int *)iVar1 = iVar1;
  }
  if ((int *)(iVar1 + 4) != (int *)0x0) {
    *(int *)(iVar1 + 4) = iVar1;
  }
  if ((int *)(iVar1 + 8) != (int *)0x0) {
    *(int *)(iVar1 + 8) = iVar1;
  }
  *(undefined2 *)(iVar1 + 0xc) = 0x101;
  return;
}


