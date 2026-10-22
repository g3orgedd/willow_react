// Source: CLCiffConversion_Data.dll @ 45005947; FUN_45005947

int * __fastcall FUN_45005947(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(char *)(iVar3 + 0xd) == '\0') {
    piVar1 = *(int **)(iVar3 + 8);
    if (*(char *)((int)*(int **)(iVar3 + 8) + 0xd) == '\0') {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)*piVar2;
      } while (*(char *)((int)piVar1 + 0xd) == '\0');
      *param_1 = (int)piVar2;
    }
    else {
      while ((iVar3 = *(int *)(iVar3 + 4), *(char *)(iVar3 + 0xd) == '\0' &&
             (*param_1 == *(int *)(iVar3 + 8)))) {
        *param_1 = iVar3;
      }
      *param_1 = iVar3;
    }
  }
  return param_1;
}


