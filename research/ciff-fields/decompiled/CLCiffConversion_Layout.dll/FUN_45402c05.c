// Source: CLCiffConversion_Layout.dll @ 45402c05; FUN_45402c05

void __fastcall FUN_45402c05(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    FID_conflict__free(_Memory);
  }
  return;
}


