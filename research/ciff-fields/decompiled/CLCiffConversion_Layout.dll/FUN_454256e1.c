// Source: CLCiffConversion_Layout.dll @ 454256e1; FUN_454256e1

undefined4 __fastcall FUN_454256e1(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      puVar1 = (undefined4 *)FUN_45425e9f(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      puVar1 = (undefined4 *)FUN_45426206(param_1,iVar2);
      FID_conflict__free((void *)*puVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  FUN_4542773b(param_1);
  return 0;
}


