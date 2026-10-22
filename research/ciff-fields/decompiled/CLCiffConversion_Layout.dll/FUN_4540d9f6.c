// Source: CLCiffConversion_Layout.dll @ 4540d9f6; FUN_4540d9f6

undefined4 FUN_4540d9f6(int param_1,uint param_2,char param_3)

{
  undefined8 *_Memory;
  undefined8 *puVar1;
  uint extraout_EAX;
  uint uVar2;
  
  if (*(uint *)(param_1 + 0x9c) < param_2) {
    _Memory = *(undefined8 **)(param_1 + 0x94);
    uVar2 = param_2 + 0x3fff & 0xffffc000;
    puVar1 = (undefined8 *)FUN_454294e2(uVar2);
    *(undefined8 **)(param_1 + 0x94) = puVar1;
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if (param_3 != '\0') {
      FUN_45429920(puVar1,_Memory,*(uint *)(param_1 + 0x98));
    }
    *(uint *)(param_1 + 0x9c) = uVar2;
    FID_conflict__free(_Memory);
    param_2 = extraout_EAX;
  }
  return CONCAT31((int3)(param_2 >> 8),1);
}


