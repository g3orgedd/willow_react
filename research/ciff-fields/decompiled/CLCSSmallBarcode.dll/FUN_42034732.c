// Source: CLCSSmallBarcode.dll @ 42034732; FUN_42034732

void __fastcall FUN_42034732(int param_1)

{
  void *pvVar1;
  void *_Memory;
  
  _Memory = *(void **)(param_1 + 8);
  while (_Memory != (void *)0x0) {
    pvVar1 = *(void **)((int)_Memory + 0x10);
    FUN_42034701((int)_Memory);
    FID_conflict__free(_Memory);
    _Memory = pvVar1;
  }
  return;
}


