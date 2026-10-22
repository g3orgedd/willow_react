// Source: CLCiffConversion_Layout.dll @ 45423d47; FUN_45423d47

undefined4 * __thiscall FUN_45423d47(void *this,ulong param_1)

{
  undefined1 *puVar1;
  
  if ((int)param_1 < 100) {
    param_1 = 1000;
  }
  *(undefined4 *)this = 0;
  *(ulong *)((int)this + 4) = param_1;
  puVar1 = ATL::AtlCoTaskMemCAlloc(param_1,1);
  *(undefined1 **)((int)this + 8) = puVar1;
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
  }
  return this;
}


