// Source: CLARiSOFT.exe @ 00e2f25e; FUN_00e2f25e

void __fastcall FUN_00e2f25e(undefined4 *param_1)

{
  undefined4 *_Memory;
  
  _Memory = (undefined4 *)*param_1;
  if (_Memory != (undefined4 *)0x0) {
    FUN_00e0a46c(_Memory);
    FID_conflict__free(_Memory);
  }
  *param_1 = 0;
  return;
}


