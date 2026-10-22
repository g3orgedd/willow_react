// Source: CLCiffConversion_Layout.dll @ 45407d7a; FUN_45407d7a

void FUN_45407d7a(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  while (cVar1 == '\0') {
    FUN_45407d7a((int *)param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_454076da(param_1 + 4);
    FID_conflict__free(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xd);
  }
  return;
}


