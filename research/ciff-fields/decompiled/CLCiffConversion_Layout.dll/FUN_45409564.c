// Source: CLCiffConversion_Layout.dll @ 45409564; FUN_45409564

undefined4 __cdecl FUN_45409564(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  iVar2 = 0xc;
  *param_2 = '{';
  iVar6 = param_1 - (int)param_2;
  iVar3 = 8;
  pcVar5 = param_2;
  do {
    pcVar5 = pcVar5 + 1;
    iVar1 = -iVar2;
    *pcVar5 = pcVar5[iVar6] - (char)iVar2;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 1;
    }
    else {
      iVar2 = iVar1 + -1;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 6;
  iVar3 = 4;
  param_2[9] = '-';
  pcVar5 = param_2 + 10;
  iVar1 = iVar3;
  do {
    iVar4 = -iVar2;
    *pcVar5 = pcVar5[iVar6] - (char)iVar2;
    if (iVar4 < 0) {
      iVar2 = iVar4 + 1;
    }
    else {
      iVar2 = iVar4 + -1;
    }
    pcVar5 = pcVar5 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar2 = 10;
  param_2[0xe] = '-';
  pcVar5 = param_2 + 0xf;
  iVar1 = iVar3;
  do {
    iVar4 = -iVar2;
    *pcVar5 = pcVar5[iVar6] - (char)iVar2;
    if (iVar4 < 0) {
      iVar2 = iVar4 + 1;
    }
    else {
      iVar2 = iVar4 + -1;
    }
    pcVar5 = pcVar5 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  param_2[0x13] = '-';
  pcVar5 = param_2 + 0x14;
  iVar2 = iVar3;
  do {
    iVar1 = -iVar3;
    *pcVar5 = pcVar5[iVar6] - (char)iVar3;
    if (iVar1 < 0) {
      iVar3 = iVar1 + 1;
    }
    else {
      iVar3 = iVar1 + -1;
    }
    pcVar5 = pcVar5 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0xe;
  param_2[0x18] = '-';
  pcVar5 = param_2 + 0x19;
  iVar3 = 0xc;
  do {
    iVar1 = -iVar2;
    *pcVar5 = pcVar5[iVar6] - (char)iVar2;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 1;
    }
    else {
      iVar2 = iVar1 + -1;
    }
    pcVar5 = pcVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_2[0x25] = '}';
  param_2[0x26] = '\0';
  return 1;
}


