// Source: CLCiffConversion_Layout.dll @ 45409622; FUN_45409622

void __fastcall FUN_45409622(undefined4 *param_1)

{
  int *_Memory;
  
  _Memory = (int *)*param_1;
  if (_Memory != (int *)0x0) {
    FUN_454076f2(_Memory);
    FID_conflict__free(_Memory);
  }
  *param_1 = 0;
  return;
}


