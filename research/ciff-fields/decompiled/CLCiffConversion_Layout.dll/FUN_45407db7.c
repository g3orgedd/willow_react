// Source: CLCiffConversion_Layout.dll @ 45407db7; FUN_45407db7

undefined4 * __thiscall FUN_45407db7(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)this)[1];
  puVar4 = *(undefined4 **)this;
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0xd) == '\0') {
    bVar2 = FUN_454078ec(puVar3 + 4,param_1);
    if (bVar2) {
      puVar1 = (undefined4 *)puVar3[2];
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
      puVar4 = puVar3;
    }
  }
  return puVar4;
}


