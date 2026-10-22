// Source: CLARiSOFT.exe @ 00e2f27c; FUN_00e2f27c

void __fastcall FUN_00e2f27c(undefined4 *param_1)

{
  int *_Memory;
  
  _Memory = (int *)*param_1;
  if (_Memory != (int *)0x0) {
    FUN_00e56254(_Memory);
    FID_conflict__free(_Memory);
  }
  *param_1 = 0;
  return;
}


