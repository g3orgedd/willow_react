// Source: CiffMgr.dll @ 6810c82e; FUN_6810c82e

int FUN_6810c82e(int param_1,int param_2,uint *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    piVar5 = *(int **)(param_1 + 8);
    iVar3 = 0;
    if (piVar5 < *(int **)(param_1 + 0xc)) {
      do {
        puVar1 = (undefined4 *)*piVar5;
        if ((puVar1 != (undefined4 *)0x0) &&
           ((param_3 == (uint *)0x0 ||
            (bVar2 = FUN_6810f083(param_3,(uint *)*puVar1), CONCAT31(extraout_var,bVar2) != 0)))) {
          iVar3 = 0;
          piVar4 = (int *)(*(code *)puVar1[6])();
          iVar3 = FUN_6810cb05((GUID *)*puVar1,piVar4,iVar3);
          if (iVar3 < 0) {
            return iVar3;
          }
          iVar3 = (*(code *)puVar1[1])(0);
          if (iVar3 < 0) {
            return iVar3;
          }
        }
        piVar5 = piVar5 + 1;
      } while (piVar5 < *(int **)(param_1 + 0xc));
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    if (param_2 != 0) {
      iVar3 = FUN_6810cf8f(*(TLIBATTR **)(param_1 + 4),(wchar_t *)0x0);
    }
  }
  return iVar3;
}


