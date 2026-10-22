// Source: CLCiffConversion_Data.dll @ 4502d635; FUN_4502d635

void __cdecl FUN_4502d635(byte *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  bool bVar4;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_45021444(local_14,param_2);
  iVar2 = _tolower((int)(char)*param_1);
  bVar4 = iVar2 == 0x65;
  while (!bVar4) {
    param_1 = param_1 + 1;
    iVar2 = _isdigit((uint)*param_1);
    bVar4 = iVar2 == 0;
  }
  iVar2 = _tolower((int)(char)*param_1);
  if (iVar2 == 0x78) {
    param_1 = param_1 + 2;
  }
  bVar3 = *param_1;
  *param_1 = *(byte *)**(undefined4 **)(local_14[0] + 0x84);
  do {
    param_1 = param_1 + 1;
    bVar1 = *param_1;
    *param_1 = bVar3;
    bVar3 = bVar1;
  } while (*param_1 != 0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}


