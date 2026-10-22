// Source: CLCiffConversion_Layout.dll @ 4543ad28; FUN_4543ad28

ushort __cdecl FUN_4543ad28(int param_1,int *param_2)

{
  ushort uVar1;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_2);
  if (*(int *)(local_14[0] + 0x74) < 2) {
    uVar1 = *(ushort *)(*(int *)(local_14[0] + 0x90) + param_1 * 2) & 0x80;
  }
  else {
    uVar1 = FUN_454344e5(param_1,0x80,local_14);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}


