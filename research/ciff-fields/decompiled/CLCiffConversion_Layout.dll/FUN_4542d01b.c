// Source: CLCiffConversion_Layout.dll @ 4542d01b; FUN_4542d01b

ushort __cdecl FUN_4542d01b(uint param_1,int *param_2)

{
  ushort uVar1;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_2);
  uVar1 = *(ushort *)(*(int *)(local_14[0] + 0x90) + (param_1 & 0xff) * 2);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1 & 0x8000;
}


