// Source: CLCiffConversion_Data.dll @ 4501d1ec; FUN_4501d1ec

double * __cdecl FUN_4501d1ec(double *param_1,double *param_2,int *param_3)

{
  double dVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  *param_1 = DAT_4503d998;
  uVar2 = FUN_4501dc99(param_2);
  if (((char)uVar2 != '\0') && (uVar2 = FUN_4501dc59(param_3), (char)uVar2 != '\0')) {
    *param_1 = *param_2;
    if (*param_3 != 0) {
      FUN_4501d3c2(param_1,(short)*param_3);
    }
    if (param_3[1] != 0) {
      FUN_4501d29d(param_1,param_3[1]);
    }
    dVar1 = *(double *)(param_3 + 2);
    fVar3 = FUN_4501d47f(*param_1);
    fVar3 = FUN_4501dcc4((double)(fVar3 + (float10)dVar1));
    *param_1 = (double)fVar3;
  }
  return param_1;
}


