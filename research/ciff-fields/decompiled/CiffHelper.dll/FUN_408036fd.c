// Source: CiffHelper.dll @ 408036fd; FUN_408036fd

void FUN_408036fd(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)PTR_DAT_40862010) {
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


