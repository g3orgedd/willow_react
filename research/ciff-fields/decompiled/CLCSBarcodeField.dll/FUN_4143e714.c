// Source: CLCSBarcodeField.dll @ 4143e714; FUN_4143e714

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4143e714(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,&param_1);
  iVar3 = 1000;
  iVar2 = (int)(DAT_41481000 / ((double)(float)param_1 * _DAT_41482570));
  do {
    iVar1 = iVar2;
    iVar3 = iVar3 + 1000;
    iVar2 = (int)((double)iVar3 / ((double)(float)param_1 * _DAT_41482570));
  } while (iVar2 < 0x5dc);
  return iVar1;
}


