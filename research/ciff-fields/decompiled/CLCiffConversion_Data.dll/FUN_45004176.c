// Source: CLCiffConversion_Data.dll @ 45004176; FUN_45004176

void FUN_45004176(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)PTR_DAT_45051018) {
    LOCK();
    iVar1 = *param_1;
    *param_1 = *param_1 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      FID_conflict__free(param_1);
    }
  }
  return;
}


