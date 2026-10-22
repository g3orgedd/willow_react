// Source: CiffMgr.dll @ 681146ee; FUN_681146ee

void FUN_681146ee(int param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      cVar1 = FUN_681148ec(*(ushort *)(param_1 + uVar2 * 2),"",5);
      *(char *)(uVar2 + param_3) = cVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}


