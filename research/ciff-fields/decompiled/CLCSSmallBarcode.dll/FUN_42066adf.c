// Source: CLCSSmallBarcode.dll @ 42066adf; FUN_42066adf

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_42066adf(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  float10 fVar3;
  double dVar4;
  
  piVar1 = (int *)*param_2;
  if (piVar1 == (int *)0x0) {
    fVar3 = (float10)0;
  }
  else {
    param_2 = (int *)0x0;
    iVar2 = 1;
    (**(code **)(*piVar1 + 0x2c))(piVar1,&param_2);
    if (((double)(float)param_2 == 0.0) || (*(double *)(param_1 + 0x28) == 0.0)) {
      fVar3 = (float10)0;
    }
    else {
      while (dVar4 = (((double)iVar2 / (double)(float)param_2) * DAT_42089818) /
                     *(double *)(param_1 + 0x28), dVar4 <= _DAT_4209e1b0) {
        iVar2 = iVar2 + 1;
      }
      fVar3 = (float10)((float)(int)(dVar4 * DAT_42092e78) / _DAT_4209c3c8);
    }
  }
  return fVar3;
}


