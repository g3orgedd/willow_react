// Source: CLCiffConversion_Layout.dll @ 4542caf6; FUN_4542caf6

uint __cdecl FUN_4542caf6(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_3);
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
    uVar6 = 0x7fffffff;
  }
  else if (*(int *)(local_10 + 8) == 0) {
    uVar6 = _strcmp((char *)param_1,(char *)param_2);
  }
  else {
    do {
      bVar1 = *param_1;
      pbVar8 = param_1 + 1;
      uVar5 = (uint)bVar1;
      if (((*(byte *)(bVar1 + 0x19 + local_10) & 4) != 0) &&
         (bVar2 = *pbVar8, uVar5 = 0, bVar2 != 0)) {
        pbVar8 = param_1 + 2;
        uVar5 = (uint)CONCAT11(bVar1,bVar2);
      }
      bVar1 = *param_2;
      pbVar9 = param_2 + 1;
      uVar6 = 0;
      uVar7 = (uint)bVar1;
      if (((*(byte *)(bVar1 + 0x19 + local_10) & 4) != 0) &&
         (bVar2 = *pbVar9, uVar7 = uVar6, bVar2 != 0)) {
        pbVar9 = param_2 + 2;
        uVar7 = (uint)CONCAT11(bVar1,bVar2);
      }
      uVar4 = (ushort)uVar5;
      if ((ushort)uVar7 != uVar4) {
        uVar6 = (-(uint)((ushort)uVar7 < uVar4) & 2) - 1;
        break;
      }
      param_1 = pbVar8;
      param_2 = pbVar9;
    } while (uVar4 != 0);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar6;
}


