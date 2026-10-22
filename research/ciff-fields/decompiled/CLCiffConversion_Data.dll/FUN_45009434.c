// Source: CLCiffConversion_Data.dll @ 45009434; FUN_45009434

void __thiscall FUN_45009434(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  errno_t eVar2;
  
  HVar1 = VariantClear(param_1);
  if (-1 < HVar1) {
    eVar2 = _memcpy_s(param_1,0x10,this,0x10);
    FUN_450026fa(eVar2);
    *(undefined2 *)this = 0;
  }
  return;
}


