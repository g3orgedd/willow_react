// Source: CLCiffConversion_Layout.dll @ 4543b087; FUN_4543b087

int __cdecl FUN_4543b087(char *param_1,uint param_2,int param_3,int param_4)

{
  char *_Str;
  int *piVar1;
  char *pcVar2;
  size_t sVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  
  pcVar5 = *(char **)(param_4 + 0xc);
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    piVar1 = __errno();
    iVar6 = 0x16;
  }
  else {
    *param_1 = '\0';
    iVar6 = param_3;
    if (param_3 < 1) {
      iVar6 = 0;
    }
    if (iVar6 + 1U < param_2) {
      *param_1 = '0';
      _Str = param_1 + 1;
      pcVar2 = _Str;
      for (; 0 < param_3; param_3 = param_3 + -1) {
        cVar4 = *pcVar5;
        if (cVar4 == '\0') {
          cVar4 = '0';
        }
        else {
          pcVar5 = pcVar5 + 1;
        }
        *pcVar2 = cVar4;
        pcVar2 = pcVar2 + 1;
      }
      *pcVar2 = '\0';
      if ((-1 < param_3) && ('4' < *pcVar5)) {
        while (pcVar2 = pcVar2 + -1, *pcVar2 == '9') {
          *pcVar2 = '0';
        }
        *pcVar2 = *pcVar2 + '\x01';
      }
      if (*param_1 == '1') {
        *(int *)(param_4 + 4) = *(int *)(param_4 + 4) + 1;
      }
      else {
        sVar3 = _strlen(_Str);
        FUN_4542a090((undefined8 *)param_1,(undefined8 *)_Str,sVar3 + 1);
      }
      return 0;
    }
    piVar1 = __errno();
    iVar6 = 0x22;
  }
  *piVar1 = iVar6;
  FUN_45432798();
  return iVar6;
}


