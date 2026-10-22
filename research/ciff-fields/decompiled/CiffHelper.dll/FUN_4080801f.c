// Source: CiffHelper.dll @ 4080801f; FUN_4080801f

void __thiscall FUN_4080801f(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  errno_t eVar2;
  
  HVar1 = VariantClear(param_1);
  if (-1 < HVar1) {
    eVar2 = _memcpy_s(param_1,0x10,this,0x10);
    FUN_4080330f(eVar2);
    *(undefined2 *)this = 0;
  }
  return;
}


