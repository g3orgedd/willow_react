// Source: CLCiffConversion_Layout.dll @ 454395bc; FUN_454395bc

int __cdecl FUN_454395bc(char *param_1,int param_2,char *param_3,int param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  if (param_4 == 0) {
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_454395db:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = '\0';
          return 0;
        }
        if (param_3 != (char *)0x0) {
          iVar5 = param_2;
          if (param_4 == -1) {
            iVar3 = (int)param_1 - (int)param_3;
            do {
              cVar1 = *param_3;
              param_3[iVar3] = cVar1;
              param_3 = param_3 + 1;
              if (cVar1 == '\0') break;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          else {
            pcVar4 = param_1;
            do {
              cVar1 = pcVar4[(int)param_3 - (int)param_1];
              *pcVar4 = cVar1;
              pcVar4 = pcVar4 + 1;
              if ((cVar1 == '\0') || (iVar5 = iVar5 + -1, iVar5 == 0)) break;
              param_4 = param_4 + -1;
            } while (param_4 != 0);
            if (param_4 == 0) {
              *pcVar4 = '\0';
            }
          }
          if (iVar5 != 0) {
            return 0;
          }
          if (param_4 == -1) {
            param_1[param_2 + -1] = '\0';
            return 0x50;
          }
          *param_1 = '\0';
          piVar2 = __errno();
          iVar5 = 0x22;
          goto LAB_454395fb;
        }
        *param_1 = '\0';
      }
    }
  }
  else if (param_1 != (char *)0x0) goto LAB_454395db;
  piVar2 = __errno();
  iVar5 = 0x16;
LAB_454395fb:
  *piVar2 = iVar5;
  FUN_45432798();
  return iVar5;
}


