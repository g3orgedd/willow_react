// Source: CiffMgr.dll @ 6810880b; FUN_6810880b

int FUN_6810880b(int param_1,uint param_2,VARIANTARG *param_3,uint *param_4)

{
  VARIANTARG *pvargSrc;
  VARIANTARG *pvarg;
  int iVar1;
  uint local_8;
  
  if ((param_3 == (VARIANTARG *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    iVar1 = -0x7fffbffd;
  }
  else {
    if (param_4 != (uint *)0x0) {
      *param_4 = 0;
    }
    if (*(int *)(param_1 + 8) == 0) {
      iVar1 = -0x7fffbffb;
    }
    else {
      local_8 = 0;
      iVar1 = 0;
      pvarg = param_3;
      do {
        pvargSrc = *(VARIANTARG **)(param_1 + 0xc);
        if ((pvargSrc == *(VARIANTARG **)(*(int *)(param_1 + 8) + 4)) || (param_2 <= local_8))
        break;
        (param_3->n1).n2.vt = 0;
        iVar1 = VariantCopy(param_3,pvargSrc);
        if (iVar1 < 0) {
          for (; pvarg < param_3; pvarg = pvarg + 1) {
            VariantClear(pvarg);
          }
          local_8 = 0;
        }
        else {
          param_3 = param_3 + 1;
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x10;
          local_8 = local_8 + 1;
        }
      } while (-1 < iVar1);
      if (-1 < iVar1) {
        if (param_4 != (uint *)0x0) {
          *param_4 = local_8;
        }
        if (local_8 < param_2) {
          iVar1 = 1;
        }
      }
    }
  }
  return iVar1;
}


