// Source: CLCSSmallBarcode.dll @ 4200a372; FUN_4200a372

void __fastcall FUN_4200a372(int *param_1)

{
  BOOL BVar1;
  
  if (*param_1 != 0) {
    BVar1 = DeleteObject((HGDIOBJ)*param_1);
    if (BVar1 != 0) {
      *param_1 = 0;
    }
  }
  return;
}


