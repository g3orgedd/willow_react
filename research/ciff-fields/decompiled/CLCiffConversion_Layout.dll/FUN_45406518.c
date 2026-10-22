// Source: CLCiffConversion_Layout.dll @ 45406518; FUN_45406518

int __cdecl FUN_45406518(ushort *param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  bool bVar8;
  
  puVar6 = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    puVar6 = *(ushort **)param_1;
  }
  puVar7 = param_2;
  if (7 < *(uint *)(param_2 + 10)) {
    puVar7 = *(ushort **)param_2;
  }
  do {
    puVar5 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      puVar5 = *(ushort **)param_1;
    }
    if (puVar6 == puVar5 + *(int *)(param_1 + 8)) {
LAB_454065b3:
      bVar8 = *(uint *)(param_1 + 8) < *(uint *)(param_2 + 8);
      if (*(uint *)(param_1 + 8) == *(uint *)(param_2 + 8)) {
        return 0;
      }
      goto LAB_454065a8;
    }
    puVar5 = param_2;
    if (7 < *(uint *)(param_2 + 10)) {
      puVar5 = *(ushort **)param_2;
    }
    if (puVar7 == puVar5 + *(int *)(param_2 + 8)) goto LAB_454065b3;
    iVar1 = FUN_4542d34f((uint)*puVar6);
    iVar2 = FUN_4542d34f((uint)*puVar7);
    if (iVar1 != iVar2) {
      uVar3 = FUN_4542d34f((uint)*puVar6);
      uVar4 = FUN_4542d34f((uint)*puVar7);
      bVar8 = uVar3 < uVar4;
LAB_454065a8:
      return (-(uint)bVar8 & 0xfffffffe) + 1;
    }
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  } while( true );
}


