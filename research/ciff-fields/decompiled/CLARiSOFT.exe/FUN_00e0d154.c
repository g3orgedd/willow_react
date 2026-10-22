// Source: CLARiSOFT.exe @ 00e0d154; FUN_00e0d154

void FUN_00e0d154(void)

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


