// Source: CLCSTextBasedField.dll @ 4246775e; FUN_4246775e

void FUN_4246775e(int param_1)

{
  ushort *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = (undefined8 *)FUN_424676bc(param_1,0x640);
  if (puVar2 != (undefined8 *)0x0) {
    if ((*(byte *)((int)puVar2 + 6) & 2) != 0) {
      puVar2 = (undefined8 *)FUN_424676bc(param_1,*(ushort *)((int)puVar2 + 0xe));
    }
    if (puVar2 != (undefined8 *)0x0) {
      puVar1 = (ushort *)(*(int *)(param_1 + 0x94) + *(int *)(puVar2 + 1) * 2);
      uVar3 = FUN_424674c1(puVar1);
      iVar4 = FUN_4246cbfd(uVar3 & 0xfffffffe);
      *(int *)(param_1 + 0xb4) = iVar4;
      if (iVar4 != 0) {
        FUN_4246d2c0((undefined8 *)(param_1 + 0xa0),puVar2,0x14);
        FUN_4246d2c0(*(undefined8 **)(param_1 + 0xb4),(undefined8 *)puVar1,uVar3);
        FUN_42467abe(param_1,*(short *)(param_1 + 0x58));
      }
    }
  }
  return;
}


