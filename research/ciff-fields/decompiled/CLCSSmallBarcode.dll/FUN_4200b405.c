// Source: CLCSSmallBarcode.dll @ 4200b405; FUN_4200b405

int FUN_4200b405(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    if (0 < param_2) {
      do {
        iVar1 = iVar1 + *(int *)(param_1 + iVar2 * 4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_2);
    }
    iVar1 = iVar1 % 0x2b;
  }
  return iVar1;
}


