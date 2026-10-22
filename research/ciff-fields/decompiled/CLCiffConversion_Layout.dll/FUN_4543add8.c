// Source: CLCiffConversion_Layout.dll @ 4543add8; FUN_4543add8

uint __cdecl FUN_4543add8(uint param_1,int *param_2)

{
  ushort uVar1;
  undefined2 extraout_var;
  uint uVar2;
  undefined2 extraout_var_00;
  int *piVar3;
  int iVar4;
  int local_1c [2];
  int local_14;
  char local_10;
  byte local_c;
  undefined1 local_b;
  CHAR local_8;
  CHAR local_7;
  undefined1 local_6;
  
  FUN_4542c8eb(local_1c,param_2);
  if (param_1 < 0x100) {
    if (*(int *)(local_1c[0] + 0x74) < 2) {
      uVar2 = *(ushort *)(*(int *)(local_1c[0] + 0x90) + param_1 * 2) & 1;
    }
    else {
      uVar1 = FUN_454344e5(param_1,1,local_1c);
      uVar2 = CONCAT22(extraout_var,uVar1);
    }
    if (uVar2 == 0) {
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
    }
    else {
      param_1 = (uint)*(byte *)(*(int *)(local_1c[0] + 0x94) + param_1);
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
    }
  }
  else {
    if ((*(int *)(local_1c[0] + 0x74) < 2) ||
       (uVar1 = FUN_4542d01b((int)param_1 >> 8 & 0xff,local_1c),
       CONCAT22(extraout_var_00,uVar1) == 0)) {
      piVar3 = __errno();
      iVar4 = 1;
      *piVar3 = 0x2a;
      local_7 = '\0';
      local_8 = (CHAR)param_1;
    }
    else {
      local_6 = 0;
      iVar4 = 2;
      local_8 = (CHAR)(param_1 >> 8);
      local_7 = (CHAR)param_1;
    }
    iVar4 = FUN_45434481(local_1c,*(wchar_t **)(local_1c[0] + 0xa8),0x100,&local_8,iVar4,
                         (LPWSTR)&local_c,3,*(UINT *)(local_1c[0] + 4),1);
    if (iVar4 == 0) {
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
    }
    else if (iVar4 == 1) {
      param_1 = (uint)local_c;
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
    }
    else {
      param_1 = (uint)CONCAT11(local_c,local_b);
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
    }
  }
  return param_1;
}


