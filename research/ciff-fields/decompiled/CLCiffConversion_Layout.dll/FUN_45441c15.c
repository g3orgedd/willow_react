// Source: CLCiffConversion_Layout.dll @ 45441c15; FUN_45441c15

uint * __cdecl FUN_45441c15(uint *param_1,uint param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_3);
  if (param_1 == (uint *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
    puVar4 = (uint *)0x0;
  }
  else if (*(int *)(local_10 + 8) == 0) {
    puVar4 = FUN_4543da50(param_1,(char)param_2);
  }
  else {
    while( true ) {
      bVar2 = (byte)*param_1;
      uVar5 = (uint)bVar2;
      puVar4 = (uint *)0x0;
      if (bVar2 == 0) break;
      if ((*(byte *)(uVar5 + 0x19 + local_10) & 4) == 0) {
        puVar6 = param_1;
        if (param_2 == uVar5) break;
      }
      else {
        bVar1 = *(byte *)((int)param_1 + 1);
        if ((bVar1 == 0) ||
           (puVar6 = (uint *)((int)param_1 + 1), puVar4 = param_1, param_2 == CONCAT11(bVar2,bVar1))
           ) goto LAB_45441c9d;
      }
      param_1 = (uint *)((int)puVar6 + 1);
    }
    if (param_2 == uVar5) {
      puVar4 = param_1;
    }
  }
LAB_45441c9d:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return puVar4;
}


