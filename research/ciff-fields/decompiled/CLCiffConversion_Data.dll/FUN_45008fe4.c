// Source: CLCiffConversion_Data.dll @ 45008fe4; FUN_45008fe4

void FUN_45008fe4(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    FUN_45008fe4((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_450088df(param_1 + 4);
    FID_conflict__free(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}


