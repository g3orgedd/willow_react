// Source: CiffMgr.dll @ 6810408a; FUN_6810408a

HRESULT __thiscall FUN_6810408a(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  errno_t eVar2;
  
  if (param_1 == (VARIANTARG *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    HVar1 = VariantClear(param_1);
    if (-1 < HVar1) {
      eVar2 = _memcpy_s(param_1,0x10,this,0x10);
      FUN_68103e74(eVar2);
      HVar1 = 0;
      *(undefined2 *)this = 0;
    }
  }
  return HVar1;
}


