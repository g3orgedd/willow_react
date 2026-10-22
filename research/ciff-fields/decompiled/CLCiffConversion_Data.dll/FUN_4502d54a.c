// Source: CLCiffConversion_Data.dll @ 4502d54a; FUN_4502d54a

void __cdecl FUN_4502d54a(char *param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int local_14 [2];
  int local_c;
  char local_8;
  char *pcVar3;
  
  FUN_45021444(local_14,param_2);
  cVar1 = *param_1;
  if (cVar1 != '\0') {
    do {
      if (cVar1 == *(char *)**(undefined4 **)(local_14[0] + 0x84)) break;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
  }
  if (*param_1 != '\0') {
    do {
      param_1 = param_1 + 1;
      cVar1 = *param_1;
      pcVar2 = param_1;
      if ((cVar1 == '\0') || (cVar1 == 'e')) break;
    } while (cVar1 != 'E');
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + -1;
    } while (*pcVar2 == '0');
    if (*pcVar2 == *(char *)**(undefined4 **)(local_14[0] + 0x84)) {
      pcVar2 = pcVar3 + -2;
    }
    do {
      cVar1 = *param_1;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + 1;
      *pcVar2 = cVar1;
    } while (cVar1 != '\0');
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}


