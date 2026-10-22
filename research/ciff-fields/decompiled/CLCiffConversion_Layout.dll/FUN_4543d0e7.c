// Source: CLCiffConversion_Layout.dll @ 4543d0e7; FUN_4543d0e7

undefined4 __cdecl FUN_4543d0e7(LPWSTR param_1,byte *param_2,uint param_3,int *param_4)

{
  uint uVar1;
  ushort uVar2;
  undefined2 extraout_var;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int local_14 [2];
  int local_c;
  char local_8;
  
  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    return 0;
  }
  if (*param_2 == 0) {
    if (param_1 == (LPWSTR)0x0) {
      return 0;
    }
    *param_1 = L'\0';
    return 0;
  }
  FUN_4542c8eb(local_14,param_4);
  if (*(int *)(local_14[0] + 0xa8) == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = (ushort)*param_2;
    }
    uVar5 = 1;
    goto LAB_4543d1c7;
  }
  uVar2 = FUN_4542d01b((uint)*param_2,local_14);
  if (CONCAT22(extraout_var,uVar2) == 0) {
    uVar5 = 1;
    iVar3 = MultiByteToWideChar(*(UINT *)(local_14[0] + 4),9,(LPCSTR)param_2,1,param_1,
                                (uint)(param_1 != (LPWSTR)0x0));
    if (iVar3 != 0) goto LAB_4543d1c7;
LAB_4543d1b9:
    piVar4 = __errno();
    uVar5 = 0xffffffff;
    *piVar4 = 0x2a;
  }
  else {
    if (*(int *)(local_14[0] + 0x74) < 2) {
LAB_4543d186:
      uVar1 = *(uint *)(local_14[0] + 0x74);
LAB_4543d189:
      if ((param_3 < uVar1) || (param_2[1] == 0)) goto LAB_4543d1b9;
    }
    else {
      uVar1 = *(uint *)(local_14[0] + 0x74);
      if ((int)param_3 < (int)uVar1) goto LAB_4543d189;
      iVar3 = MultiByteToWideChar(*(UINT *)(local_14[0] + 4),9,(LPCSTR)param_2,
                                  *(int *)(local_14[0] + 0x74),param_1,
                                  (uint)(param_1 != (LPWSTR)0x0));
      if (iVar3 == 0) goto LAB_4543d186;
    }
    uVar5 = *(undefined4 *)(local_14[0] + 0x74);
  }
LAB_4543d1c7:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    return uVar5;
  }
  return uVar5;
}


