// Source: CiffMgr.dll @ 681148ec; FUN_681148ec

char FUN_681148ec(ushort param_1,char *param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    puVar1 = (ushort *)(param_2 + 8);
    do {
      if ((*puVar1 <= param_1) && ((uint)param_1 < (uint)*puVar1 + *(int *)(puVar1 + -2))) {
        return ((char)param_1 - param_2[uVar2 * 0xc + 8]) + param_2[uVar2 * 0xc];
      }
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 6;
    } while (uVar2 < param_3);
  }
  return *param_2;
}


