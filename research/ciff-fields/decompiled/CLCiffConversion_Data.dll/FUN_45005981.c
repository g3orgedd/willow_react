// Source: CLCiffConversion_Data.dll @ 45005981; FUN_45005981

int * __fastcall FUN_45005981(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  if (*(char *)((int)piVar3 + 0xd) == '\0') {
    iVar1 = *piVar3;
    if (*(char *)(*piVar3 + 0xd) != '\0') {
      while ((piVar3 = (int *)piVar3[1], *(char *)((int)piVar3 + 0xd) == '\0' &&
             (*param_1 == *piVar3))) {
        *param_1 = (int)piVar3;
      }
      if (*(char *)(*param_1 + 0xd) != '\0') {
        return param_1;
      }
      *param_1 = (int)piVar3;
      return param_1;
    }
    do {
      iVar2 = iVar1;
      iVar1 = *(int *)(iVar2 + 8);
    } while (*(char *)(*(int *)(iVar2 + 8) + 0xd) == '\0');
  }
  else {
    iVar2 = piVar3[2];
  }
  *param_1 = iVar2;
  return param_1;
}


