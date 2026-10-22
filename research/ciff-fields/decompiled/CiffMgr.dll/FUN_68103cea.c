// Source: CiffMgr.dll @ 68103cea; FUN_68103cea

void __fastcall FUN_68103cea(int *param_1)

{
  int *_Memory;
  
  while (*param_1 != 0) {
    _Memory = (int *)*param_1;
    *param_1 = *_Memory;
    FID_conflict__free(_Memory);
  }
  return;
}


