// Source: CLCiffConversion_Layout.dll @ 45403ffc; FUN_45403ffc

void FUN_45403ffc(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)PTR_DAT_4545d10c) {
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


