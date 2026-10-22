// Source: CLCiffConversion_Data.dll @ 4502d731; FUN_4502d731

ushort __cdecl FUN_4502d731(int param_1,ushort param_2,int *param_3)

{
  ushort uVar1;
  undefined2 extraout_var;
  int iVar2;
  int local_1c [2];
  int local_14;
  char local_10;
  CHAR local_c;
  CHAR local_b;
  undefined1 local_a;
  ushort local_8 [2];
  
  FUN_45021444(local_1c,param_3);
  if (param_1 + 1U < 0x101) {
    local_8[0] = *(ushort *)(*(int *)(local_1c[0] + 0x90) + param_1 * 2);
  }
  else {
    uVar1 = FUN_450214cc(param_1 >> 8 & 0xff,local_1c);
    if (CONCAT22(extraout_var,uVar1) == 0) {
      local_b = '\0';
      iVar2 = 1;
      local_c = (CHAR)param_1;
    }
    else {
      local_a = 0;
      iVar2 = 2;
      local_c = (CHAR)((uint)param_1 >> 8);
      local_b = (CHAR)param_1;
    }
    iVar2 = FUN_45032531(local_1c,1,&local_c,iVar2,local_8,*(UINT *)(local_1c[0] + 4),1);
    if (iVar2 == 0) {
      if (local_10 != '\0') {
        *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
      }
      return 0;
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return local_8[0] & param_2;
}


