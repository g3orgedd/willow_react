// Source: CiffMgr.dll @ 6811493c; FUN_6811493c

undefined4 FUN_6811493c(byte param_1,uint *param_2,uint param_3)

{
  uint in_EAX;
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar1 = (undefined2)(in_EAX >> 0x10);
  uVar3 = 0;
  sVar2 = (short)param_2[2];
  if (param_3 != 0) {
    puVar4 = param_2;
    do {
      if ((*puVar4 <= (uint)param_1) && (in_EAX = puVar4[1] + *puVar4, param_1 < in_EAX)) {
        uVar1 = 0;
        sVar2 = ((short)param_2[uVar3 * 3 + 2] - (short)param_2[uVar3 * 3]) + (ushort)param_1;
        break;
      }
      uVar1 = (undefined2)(in_EAX >> 0x10);
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 3;
    } while (uVar3 < param_3);
  }
  return CONCAT22(uVar1,sVar2);
}


