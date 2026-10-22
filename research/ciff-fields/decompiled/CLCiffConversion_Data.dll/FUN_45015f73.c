// Source: CLCiffConversion_Data.dll @ 45015f73; FUN_45015f73

undefined4 __fastcall FUN_45015f73(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      puVar1 = (undefined4 *)FUN_450167e9(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      puVar1 = (undefined4 *)FUN_45016a80(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  FUN_4501812d(param_1);
  return 0;
}


