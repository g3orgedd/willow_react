// Source: CiffMgr.dll @ 6810d4dc; FUN_6810d4dc

HRESULT __thiscall FUN_6810d4dc(void *this,undefined4 *param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    HVar1 = 0;
    ppv = (LPVOID *)((int)this + 0x28);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_6814e1bc,(LPUNKNOWN)0x0,1,(IID *)&DAT_681496cc,ppv),
       -1 < HVar1)) {
      *param_1 = *ppv;
      (**(code **)(*(int *)*ppv + 4))(*ppv);
    }
  }
  return HVar1;
}


