// Source: CLARiSOFT.exe @ 00e384b8; FUN_00e384b8

void __fastcall FUN_00e384b8(int *param_1)

{
  int *piVar1;
  int *_Memory;
  
  piVar1 = (int *)*param_1;
  _Memory = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*param_1 + 4) = *param_1;
  param_1[1] = 0;
  if (_Memory != (int *)*param_1) {
    do {
      piVar1 = (int *)*_Memory;
      FID_conflict__free(_Memory);
      _Memory = piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  return;
}


