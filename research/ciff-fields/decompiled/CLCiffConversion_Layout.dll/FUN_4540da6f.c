// Source: CLCiffConversion_Layout.dll @ 4540da6f; FUN_4540da6f

undefined4 FUN_4540da6f(int param_1,uint param_2,char param_3)

{
  undefined8 *_Memory;
  uint uVar1;
  undefined8 *puVar2;
  uint extraout_EAX;
  
  uVar1 = param_2 & 0xffff;
  if (*(uint *)(param_1 + 0x78) < uVar1) {
    _Memory = *(undefined8 **)(param_1 + 0x74);
    uVar1 = uVar1 + 0x7f & 0xffffff80;
    puVar2 = (undefined8 *)FUN_454294e2(uVar1 * 0x14);
    *(undefined8 **)(param_1 + 0x74) = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
      return 0;
    }
    if (param_3 != '\0') {
      FUN_45429920(puVar2,_Memory,*(int *)(param_1 + 0x78) * 0x14);
    }
    *(uint *)(param_1 + 0x78) = uVar1;
    FID_conflict__free(_Memory);
    uVar1 = extraout_EAX;
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}


