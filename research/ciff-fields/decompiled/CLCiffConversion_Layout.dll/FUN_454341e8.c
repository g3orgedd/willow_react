// Source: CLCiffConversion_Layout.dll @ 454341e8; FUN_454341e8

int __cdecl FUN_454341e8(char *param_1,byte *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_3);
  if ((param_1 == (char *)0x0) || (param_2 == (byte *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    iVar4 = 0x7fffffff;
  }
  else if (*(int *)(local_14[0] + 0xa8) == 0) {
    iVar4 = ___ascii_stricmp(param_1,(char *)param_2);
  }
  else {
    iVar4 = (int)param_1 - (int)param_2;
    do {
      uVar2 = FUN_4543add8((uint)param_2[iVar4],local_14);
      uVar3 = FUN_4543add8((uint)*param_2,local_14);
      param_2 = param_2 + 1;
      if (uVar2 == 0) break;
    } while (uVar2 == uVar3);
    iVar4 = uVar2 - uVar3;
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar4;
}


