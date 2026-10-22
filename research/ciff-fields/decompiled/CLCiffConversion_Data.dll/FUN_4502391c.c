// Source: CLCiffConversion_Data.dll @ 4502391c; FUN_4502391c

void * __cdecl FUN_4502391c(LPCVOID param_1,uint param_2,uint param_3)

{
  int *piVar1;
  void *pvVar2;
  uint _NewSize;
  SIZE_T SVar3;
  
  SVar3 = 0;
  if ((param_2 == 0) || (param_3 <= 0xffffffe0 / param_2)) {
    _NewSize = param_2 * param_3;
    if (param_1 != (LPCVOID)0x0) {
      SVar3 = FUN_4502deb0(param_1);
    }
    pvVar2 = _realloc(param_1,_NewSize);
    if ((pvVar2 != (void *)0x0) && (SVar3 < _NewSize)) {
      FUN_45021c10((uint *)(SVar3 + (int)pvVar2),0,_NewSize - SVar3);
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0xc;
    pvVar2 = (void *)0x0;
  }
  return pvVar2;
}


