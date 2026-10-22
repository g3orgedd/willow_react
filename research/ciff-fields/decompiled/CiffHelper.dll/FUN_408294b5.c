// Source: CiffHelper.dll @ 408294b5; FUN_408294b5

double * __cdecl FUN_408294b5(double *param_1,double *param_2,int *param_3)

{
  double dVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  *param_1 = DAT_4084abe0;
  uVar2 = FUN_40829b07(param_2);
  if (((char)uVar2 != '\0') && (uVar2 = FUN_4081c04a(param_3), (char)uVar2 != '\0')) {
    *param_1 = *param_2;
    if (*param_3 != 0) {
      FUN_40829691(param_1,(short)*param_3);
    }
    if (param_3[1] != 0) {
      FUN_4082956c(param_1,param_3[1]);
    }
    dVar1 = *(double *)(param_3 + 2);
    fVar3 = FUN_40829735(*param_1);
    fVar3 = FUN_40829b32((double)(fVar3 + (float10)dVar1));
    FUN_408293aa(param_1,(double)fVar3);
  }
  return param_1;
}


