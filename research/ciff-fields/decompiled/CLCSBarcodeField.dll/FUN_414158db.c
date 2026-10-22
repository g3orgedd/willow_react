// Source: CLCSBarcodeField.dll @ 414158db; FUN_414158db

undefined4 __thiscall FUN_414158db(void *this,undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)((int)this + 0x94);
  while( true ) {
    if (puVar2 == *(undefined4 **)((int)this + 0x98)) {
      return 0;
    }
    cVar1 = (**(code **)(*(int *)*puVar2 + 4))(param_1);
    if (cVar1 == '\x01') break;
    puVar2 = puVar2 + 1;
  }
  return *puVar2;
}


