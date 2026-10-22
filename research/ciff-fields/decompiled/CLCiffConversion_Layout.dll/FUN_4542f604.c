// Source: CLCiffConversion_Layout.dll @ 4542f604; FUN_4542f604

int __cdecl FUN_4542f604(byte *param_1,uint param_2,byte *param_3,uint param_4,int *param_5)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  int unaff_EBX;
  uint uVar6;
  int local_18;
  int local_14;
  int local_10;
  char local_c;
  byte *local_8;
  
  uVar6 = param_4;
  if (param_4 == 0) {
    if (param_1 == (byte *)0x0) {
      if (param_2 == 0) {
        return unaff_EBX;
      }
      goto LAB_4542f63f;
    }
  }
  else if (param_1 == (byte *)0x0) goto LAB_4542f63f;
  if (param_2 == 0) {
LAB_4542f63f:
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45432798();
    return unaff_EBX;
  }
  if (param_4 == 0) {
    *param_1 = 0;
    return unaff_EBX;
  }
  if (param_3 == (byte *)0x0) {
    *param_1 = 0;
    goto LAB_4542f63f;
  }
  FUN_4542c8eb(&local_18,param_5);
  if (*(int *)(local_14 + 8) == 0) {
    FUN_454395bc((char *)param_1,param_2,(char *)param_3,param_4);
    goto LAB_4542f7be;
  }
  param_4 = param_2;
  pbVar4 = param_1;
  if (uVar6 == 0xffffffff) {
    do {
      bVar1 = *param_3;
      *pbVar4 = bVar1;
      pbVar4 = pbVar4 + 1;
      param_3 = param_3 + 1;
      if (bVar1 == 0) break;
      param_4 = param_4 - 1;
    } while (param_4 != 0);
  }
  else {
    do {
      pbVar5 = pbVar4;
      bVar1 = *param_3;
      *pbVar5 = bVar1;
      pbVar4 = pbVar5 + 1;
      param_3 = param_3 + 1;
      if ((bVar1 == 0) || (param_4 = param_4 - 1, param_4 == 0)) break;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    if (uVar6 == 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar5 + 2;
    }
  }
  if (param_4 == 0) {
    if ((*param_3 == 0) || (uVar6 == 1)) {
      pbVar4 = pbVar4 + -1;
      local_8 = pbVar4;
      while ((param_1 <= pbVar4 && (iVar3 = FUN_454395a5((uint)*pbVar4,&local_18), iVar3 != 0))) {
        pbVar4 = pbVar4 + -1;
      }
      if (((int)local_8 - (int)pbVar4 & 1U) != 0) {
        *local_8 = 0;
        goto LAB_4542f7b4;
      }
    }
    if (uVar6 == 0xffffffff) {
      if (1 < param_2) {
        pbVar5 = param_1 + (param_2 - 2);
        pbVar4 = pbVar5;
        while ((param_1 <= pbVar4 && (iVar3 = FUN_454395a5((uint)*pbVar4,&local_18), iVar3 != 0))) {
          pbVar4 = pbVar4 + -1;
        }
        if (((int)pbVar5 - (int)pbVar4 & 1U) != 0) {
          *pbVar5 = 0;
          goto LAB_4542f7be;
        }
      }
      param_1[param_2 - 1] = 0;
    }
    else {
      *param_1 = 0;
      piVar2 = __errno();
      *piVar2 = 0x22;
      FUN_45432798();
    }
  }
  else {
    if ((int)pbVar4 - (int)param_1 < 2) goto LAB_4542f7be;
    pbVar4 = pbVar4 + -2;
    pbVar5 = pbVar4;
    while ((param_1 <= pbVar5 && (iVar3 = FUN_454395a5((uint)*pbVar5,&local_18), iVar3 != 0))) {
      pbVar5 = pbVar5 + -1;
    }
    if (((int)pbVar4 - (int)pbVar5 & 1U) == 0) goto LAB_4542f7be;
    *pbVar4 = 0;
LAB_4542f7b4:
    piVar2 = __errno();
    *piVar2 = 0x2a;
  }
LAB_4542f7be:
  if (local_c == '\0') {
    return unaff_EBX;
  }
  *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  return unaff_EBX;
}


