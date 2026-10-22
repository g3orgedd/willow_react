// Source: CiffMgr.dll @ 6810d0b3; FUN_6810d0b3

undefined4 __fastcall FUN_6810d0b3(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      puVar1 = (undefined4 *)FUN_6810d548(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      puVar1 = (undefined4 *)FUN_6810d59a(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  FUN_6810e7af(param_1);
  return 0;
}


