// Source: CLCSSmallBarcode.dll @ 4200c1f4; FUN_4200c1f4

void __cdecl FUN_4200c1f4(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (param_1[3] < iVar1) {
    param_1[1] = param_1[3];
    param_1[3] = iVar1;
  }
  iVar1 = param_1[2];
  if (iVar1 < *param_1) {
    param_1[2] = *param_1;
    *param_1 = iVar1;
  }
  return;
}


