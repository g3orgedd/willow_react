// Source: CLCiffConversion_Layout.dll @ 4542d54e; FUN_4542d54e

int FUN_4542d54e(uint param_1,char *param_2,uint param_3,uint param_4,uint param_5)

{
  ulonglong uVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  int iStack_14;
  
  if (param_2 == (char *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
    return 0x16;
  }
  if (param_3 != 0) {
    *param_2 = '\0';
    if (param_3 <= (param_5 != 0) + 1) {
      piVar3 = __errno();
      iStack_14 = 0x22;
      goto LAB_4542d5fd;
    }
    iStack_14 = 0x22;
    if (param_4 - 2 < 0x23) {
      pcVar5 = param_2;
      if (param_5 != 0) {
        *param_2 = '-';
        param_1 = -param_1;
        pcVar5 = param_2 + 1;
      }
      param_5 = (uint)(param_5 != 0);
      pcVar2 = pcVar5;
      do {
        pcVar6 = pcVar2;
        uVar1 = (ulonglong)param_1;
        param_1 = param_1 / param_4;
        cVar4 = (char)(uVar1 % (ulonglong)param_4);
        if ((uint)(uVar1 % (ulonglong)param_4) < 10) {
          cVar4 = cVar4 + '0';
        }
        else {
          cVar4 = cVar4 + 'W';
        }
        *pcVar6 = cVar4;
        param_5 = param_5 + 1;
      } while ((param_1 != 0) && (pcVar2 = pcVar6 + 1, param_5 < param_3));
      if (param_5 < param_3) {
        pcVar6[1] = '\0';
        do {
          cVar4 = *pcVar6;
          *pcVar6 = *pcVar5;
          pcVar6 = pcVar6 + -1;
          *pcVar5 = cVar4;
          pcVar5 = pcVar5 + 1;
        } while (pcVar5 < pcVar6);
        return 0;
      }
      *param_2 = '\0';
      piVar3 = __errno();
      goto LAB_4542d5fd;
    }
  }
  piVar3 = __errno();
  iStack_14 = 0x16;
LAB_4542d5fd:
  *piVar3 = iStack_14;
  FUN_45432798();
  return iStack_14;
}


