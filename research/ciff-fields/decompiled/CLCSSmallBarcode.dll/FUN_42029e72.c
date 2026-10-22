// Source: CLCSSmallBarcode.dll @ 42029e72; FUN_42029e72

uint FUN_42029e72(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 uint *param_7,void *param_8)

{
  int iVar1;
  
  if ((param_5 < param_3 + param_1) && ((*param_7 & 2) == 0)) {
    *param_7 = *param_7 | 2;
    iVar1 = FUN_420059bf(param_8,L"Barcode overruns right of image. ");
    if (iVar1 < 0) goto LAB_42029f1d;
  }
  if ((param_1 < 0) && ((*param_7 & 1) == 0)) {
    *param_7 = *param_7 | 1;
    iVar1 = FUN_420059bf(param_8,L"Barcode overruns left of image. ");
    if (iVar1 < 0) goto LAB_42029f1d;
  }
  if ((param_6 < param_4 + param_2) && ((*param_7 & 8) == 0)) {
    *param_7 = *param_7 | 8;
    iVar1 = FUN_420059bf(param_8,L"Barcode overruns bottom of image. ");
    if (iVar1 < 0) goto LAB_42029f1d;
  }
  if ((param_2 < 0) && ((*param_7 & 4) == 0)) {
    *param_7 = *param_7 | 4;
    iVar1 = FUN_420059bf(param_8,L"Barcode overruns top of image. ");
    if (iVar1 < 0) {
LAB_42029f1d:
                    /* WARNING: Subroutine does not return */
      FUN_4200345c(iVar1);
    }
  }
  return -(uint)(*param_7 != 0) & 0x4022a;
}


