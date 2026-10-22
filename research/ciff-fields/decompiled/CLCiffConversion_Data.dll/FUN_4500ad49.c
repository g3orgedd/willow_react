// Source: CLCiffConversion_Data.dll @ 4500ad49; FUN_4500ad49

void __fastcall FUN_4500ad49(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    FID_conflict__free(_Memory);
  }
  return;
}


