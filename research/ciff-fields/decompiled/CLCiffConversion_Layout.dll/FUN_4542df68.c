// Source: CLCiffConversion_Layout.dll @ 4542df68; FUN_4542df68

int __cdecl FUN_4542df68(short *param_1,int param_2,short *param_3,int param_4)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  if (param_4 == 0) {
    if (param_1 == (short *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_4542df87:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = 0;
          return 0;
        }
        if (param_3 != (short *)0x0) {
          iVar5 = param_2;
          if (param_4 == -1) {
            iVar3 = (int)param_1 - (int)param_3;
            do {
              sVar1 = *param_3;
              *(short *)(iVar3 + (int)param_3) = sVar1;
              param_3 = param_3 + 1;
              if (sVar1 == 0) break;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          else {
            psVar4 = param_1;
            do {
              sVar1 = *(short *)(((int)param_3 - (int)param_1) + (int)psVar4);
              *psVar4 = sVar1;
              psVar4 = psVar4 + 1;
              if ((sVar1 == 0) || (iVar5 = iVar5 + -1, iVar5 == 0)) break;
              param_4 = param_4 + -1;
            } while (param_4 != 0);
            if (param_4 == 0) {
              *psVar4 = 0;
            }
          }
          if (iVar5 != 0) {
            return 0;
          }
          if (param_4 == -1) {
            param_1[param_2 + -1] = 0;
            return 0x50;
          }
          *param_1 = 0;
          piVar2 = __errno();
          iVar5 = 0x22;
          goto LAB_4542dfac;
        }
        *param_1 = 0;
      }
    }
  }
  else if (param_1 != (short *)0x0) goto LAB_4542df87;
  piVar2 = __errno();
  iVar5 = 0x16;
LAB_4542dfac:
  *piVar2 = iVar5;
  FUN_45432798();
  return iVar5;
}


