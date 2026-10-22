// Source: CLCiffConversion_Layout.dll @ 45439535; FUN_45439535

undefined4 __cdecl FUN_45439535(int *param_1,uint param_2,uint param_3,byte param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  
  FUN_4542c8eb(&local_14,param_1);
  if ((*(byte *)(local_10 + 0x19 + (param_2 & 0xff)) & param_4) == 0) {
    uVar2 = 0;
    if (param_3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(*(int *)(local_14 + 0x90) + (param_2 & 0xff) * 2) & param_3;
    }
    if (uVar1 == 0) goto LAB_4543957b;
  }
  uVar2 = 1;
LAB_4543957b:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar2;
}


