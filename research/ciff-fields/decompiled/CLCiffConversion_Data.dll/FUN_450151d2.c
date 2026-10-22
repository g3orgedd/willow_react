// Source: CLCiffConversion_Data.dll @ 450151d2; FUN_450151d2

undefined4 * __thiscall FUN_450151d2(void *this,int param_1)

{
  size_t _Size;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  _Size = FUN_4501453c(param_1,8);
  puVar1 = _malloc(_Size);
  puVar2 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *(undefined4 *)this;
    puVar2 = puVar1 + 2;
    *(undefined4 **)this = puVar1;
  }
  return puVar2;
}


