// Source: CLCiffConversion_Data.dll @ 450154c9; FUN_450154c9

int FUN_450154c9(int param_1,int param_2,uint *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar4 = 0;
  piVar5 = *(int **)(param_1 + 8);
  if (piVar5 < *(int **)(param_1 + 0xc)) {
    do {
      puVar1 = (undefined4 *)*piVar5;
      if ((puVar1 != (undefined4 *)0x0) &&
         ((param_3 == (uint *)0x0 ||
          (bVar2 = FUN_45018acf(param_3,(uint *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
        iVar6 = 1;
        iVar4 = (*(code *)puVar1[1])();
        if (iVar4 < 0) {
          return iVar4;
        }
        piVar3 = (int *)(*(code *)puVar1[6])(1);
        iVar4 = FUN_450158ac((GUID *)*puVar1,piVar3,iVar6);
        if (iVar4 < 0) {
          return iVar4;
        }
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 < *(int **)(param_1 + 0xc));
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  if (param_2 != 0) {
    iVar4 = FUN_45015b73(*(HMODULE *)(param_1 + 4),(wchar_t *)0x0);
  }
  return iVar4;
}


