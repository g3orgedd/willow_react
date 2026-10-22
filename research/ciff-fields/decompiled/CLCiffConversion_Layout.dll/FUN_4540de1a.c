// Source: CLCiffConversion_Layout.dll @ 4540de1a; FUN_4540de1a

void FUN_4540de1a(int param_1)

{
  ushort *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = (undefined8 *)FUN_4540dd78(param_1,0x640);
  if (puVar2 != (undefined8 *)0x0) {
    if ((*(byte *)((int)puVar2 + 6) & 2) != 0) {
      puVar2 = (undefined8 *)FUN_4540dd78(param_1,*(ushort *)((int)puVar2 + 0xe));
    }
    if (puVar2 != (undefined8 *)0x0) {
      puVar1 = (ushort *)(*(int *)(param_1 + 0x94) + *(int *)(puVar2 + 1) * 2);
      uVar3 = FUN_4540db7d(puVar1);
      iVar4 = FUN_454294e2(uVar3 & 0xfffffffe);
      *(int *)(param_1 + 0xb4) = iVar4;
      if (iVar4 != 0) {
        FUN_45429920((undefined8 *)(param_1 + 0xa0),puVar2,0x14);
        FUN_45429920(*(undefined8 **)(param_1 + 0xb4),(undefined8 *)puVar1,uVar3);
        FUN_4540e1ae(param_1,*(short *)(param_1 + 0x58));
      }
    }
  }
  return;
}


