// Source: CLCSSmallBarcode.dll @ 42003eea; FUN_42003eea

void __fastcall FUN_42003eea(undefined4 *param_1)

{
  int *_Memory;
  
  _Memory = (int *)*param_1;
  if (_Memory != (int *)0x0) {
    FUN_4200a372(_Memory);
    FID_conflict__free(_Memory);
  }
  *param_1 = 0;
  return;
}


