// Source: CLCiffConversion_Layout.dll @ 45441cb2; FUN_45441cb2

int __cdecl FUN_45441cb2(char *param_1,byte *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_14 [2];
  int local_c;
  char local_8;
  
  if (param_3 == 0) {
    iVar4 = 0;
  }
  else {
    FUN_4542c8eb(local_14,param_4);
    iVar4 = 0x7fffffff;
    if (((param_1 == (char *)0x0) || (param_2 == (byte *)0x0)) || (0x7fffffff < param_3)) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_45432798();
    }
    else if (*(int *)(local_14[0] + 0xa8) == 0) {
      iVar4 = ___ascii_strnicmp(param_1,(char *)param_2,param_3);
    }
    else {
      iVar4 = (int)param_1 - (int)param_2;
      do {
        uVar2 = FUN_4543add8((uint)param_2[iVar4],local_14);
        uVar3 = FUN_4543add8((uint)*param_2,local_14);
        param_2 = param_2 + 1;
        param_3 = param_3 - 1;
        if ((param_3 == 0) || (uVar2 == 0)) break;
      } while (uVar2 == uVar3);
      iVar4 = uVar2 - uVar3;
    }
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  return iVar4;
}


