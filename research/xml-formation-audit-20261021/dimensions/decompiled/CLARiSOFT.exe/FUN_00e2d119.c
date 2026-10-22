// Source: CLARiSOFT.exe @ 00e2d119; FUN_00e2d119

bool __fastcall FUN_00e2d119(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  return iVar1 != 0;
}


