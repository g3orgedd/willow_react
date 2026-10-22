// Source: CLCSSmallBarcode.dll @ 4200b894; FUN_4200b894

undefined4 __fastcall FUN_4200b894(void *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *local_8;
  
  local_8 = param_1;
  piVar1 = (int *)FUN_4200be36(param_1,*(int *)((int)param_1 + 0x38));
  uVar2 = (**(code **)(*piVar1 + 4))
                    (*(int *)((int)param_1 + 0x28),(int)param_1 + 0x2b8,&local_8,
                     (int)param_1 + 0x100);
  FUN_4200572b((void *)((int)param_1 + 0x58),(int *)((int)param_1 + 0x28));
  return uVar2;
}


