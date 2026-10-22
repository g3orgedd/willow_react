// Source: CLARiSOFT.exe @ 00e06141; FUN_00e06141

void FUN_00e06141(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)PTR_DAT_00f35010) {
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


