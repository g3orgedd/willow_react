// Source: CLCiffConversion_Data.dll @ 4501533e; FUN_4501533e

void FUN_4501533e(int param_1)

{
  undefined4 *puVar1;
  undefined4 *_Memory;
  
  if (param_1 == 0) {
    RaiseException(0xc0000005,1,0,(ULONG_PTR *)0x0);
  }
  _Memory = *(undefined4 **)(param_1 + 8);
  while (_Memory != (undefined4 *)0x0) {
    (*(code *)*_Memory)(_Memory[1]);
    puVar1 = (undefined4 *)_Memory[2];
    FID_conflict__free(_Memory);
    _Memory = puVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}


