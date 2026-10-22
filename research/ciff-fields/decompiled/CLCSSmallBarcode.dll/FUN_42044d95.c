// Source: CLCSSmallBarcode.dll @ 42044d95; FUN_42044d95

undefined4 __thiscall FUN_42044d95(void *this,undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)((int)this + 0x88);
  while( true ) {
    if (puVar2 == *(undefined4 **)((int)this + 0x8c)) {
      return 0;
    }
    cVar1 = (**(code **)(*(int *)*puVar2 + 4))(param_1);
    if (cVar1 == '\x01') break;
    puVar2 = puVar2 + 1;
  }
  return *puVar2;
}


