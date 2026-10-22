// Source: CLCiffConversion_Data.dll @ 45007a11; FUN_45007a11

undefined4 * __thiscall FUN_45007a11(void *this,wchar_t *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(undefined4 **)this)[1];
  puVar4 = *(undefined4 **)this;
  while (puVar3 = puVar1, *(char *)((int)puVar3 + 0xd) == '\0') {
    iVar2 = FUN_45007b0d(puVar3 + 4,param_1);
    if (iVar2 < 0) {
      puVar1 = (undefined4 *)puVar3[2];
    }
    else {
      puVar1 = (undefined4 *)*puVar3;
      puVar4 = puVar3;
    }
  }
  return puVar4;
}


