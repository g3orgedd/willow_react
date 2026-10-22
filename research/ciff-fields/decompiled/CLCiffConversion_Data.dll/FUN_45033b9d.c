// Source: CLCiffConversion_Data.dll @ 45033b9d; FUN_45033b9d

ushort __cdecl FUN_45033b9d(int param_1,int *param_2)

{
  ushort uVar1;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_45021444(local_14,param_2);
  if (*(int *)(local_14[0] + 0x74) < 2) {
    uVar1 = *(ushort *)(*(int *)(local_14[0] + 0x90) + param_1 * 2) & 4;
  }
  else {
    uVar1 = FUN_4502d731(param_1,4,local_14);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}


