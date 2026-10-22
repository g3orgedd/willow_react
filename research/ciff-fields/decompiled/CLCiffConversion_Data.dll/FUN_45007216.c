// Source: CLCiffConversion_Data.dll @ 45007216; FUN_45007216

void __fastcall FUN_45007216(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(*param_1 + -8) != 0) {
    if (-1 < *(int *)(*param_1 + -0xc)) {
      if ((undefined *)(*param_1 + -0xc) != PTR_DAT_45051018) {
        piVar2 = (int *)(*param_1 + -0xc);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar1 == 1 || iVar1 + -1 < 0) {
          FID_conflict__free((void *)(*param_1 + -0xc));
        }
        *param_1 = (int)PTR_DAT_4505101c;
      }
      return;
    }
    FUN_45002365(param_1,L"");
  }
  return;
}


