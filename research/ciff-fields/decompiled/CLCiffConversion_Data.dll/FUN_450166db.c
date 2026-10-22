// Source: CLCiffConversion_Data.dll @ 450166db; FUN_450166db

HRESULT __thiscall FUN_450166db(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  HVar1 = 0;
  ppv = (LPVOID *)((int)this + 0x28);
  if ((*ppv == (LPVOID)0x0) &&
     (HVar1 = CoCreateInstance((IID *)&DAT_45041784,(LPUNKNOWN)0x0,1,(IID *)&DAT_4503f9bc,ppv),
     HVar1 < 0)) {
    return HVar1;
  }
  *param_1 = *ppv;
  (**(code **)(*(int *)*ppv + 4))(*ppv);
  return HVar1;
}


