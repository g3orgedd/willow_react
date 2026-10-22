// Source: CLCiffConversion_Layout.dll @ 4542e700; FUN_4542e700

undefined4 __cdecl
FUN_4542e700(char *param_1,char *param_2,uint param_3,char *param_4,uint param_5,char *param_6,
            uint param_7,char *param_8,uint param_9)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  bVar2 = false;
  if (param_1 != (char *)0x0) {
    if (param_2 == (char *)0x0) {
      if (param_3 == 0) {
LAB_4542e733:
        if (param_4 == (char *)0x0) {
          if (param_5 == 0) {
LAB_4542e747:
            if (param_6 == (char *)0x0) {
              if (param_7 == 0) {
LAB_4542e75b:
                if (param_8 == (char *)0x0) {
                  if (param_9 == 0) {
LAB_4542e76f:
                    iVar3 = 1;
                    pcVar6 = param_1;
                    do {
                      if (*pcVar6 == '\0') break;
                      pcVar6 = pcVar6 + 1;
                      iVar3 = iVar3 + -1;
                    } while (iVar3 != 0);
                    if (*pcVar6 == ':') {
                      if (param_2 != (char *)0x0) {
                        if (param_3 < 3) goto LAB_4542e8a7;
                        FUN_454395bc(param_2,param_3,param_1,2);
                      }
                      param_1 = pcVar6 + 1;
                    }
                    else if (param_2 != (char *)0x0) {
                      *param_2 = '\0';
                    }
                    pcVar6 = (char *)0x0;
                    pcVar7 = param_1;
                    if (*param_1 == '\0') {
LAB_4542e818:
                      pcVar8 = param_1;
                      if (param_4 != (char *)0x0) {
                        *param_4 = '\0';
                      }
                    }
                    else {
                      pcVar8 = (char *)0x0;
                      do {
                        iVar3 = FUN_4543958f((int)*pcVar7);
                        if (iVar3 == 0) {
                          cVar1 = *pcVar7;
                          if ((cVar1 == '/') || (cVar1 == '\\')) {
                            pcVar8 = pcVar7 + 1;
                          }
                          else if (cVar1 == '.') {
                            pcVar6 = pcVar7;
                          }
                        }
                        else {
                          pcVar7 = pcVar7 + 1;
                        }
                        pcVar7 = pcVar7 + 1;
                      } while (*pcVar7 != '\0');
                      if (pcVar8 == (char *)0x0) goto LAB_4542e818;
                      if (param_4 != (char *)0x0) {
                        if (param_5 <= (uint)((int)pcVar8 - (int)param_1)) goto LAB_4542e8a7;
                        FUN_454395bc(param_4,param_5,param_1,(int)pcVar8 - (int)param_1);
                      }
                    }
                    param_1 = pcVar8;
                    if ((pcVar6 == (char *)0x0) || (pcVar6 < pcVar8)) {
                      if (param_6 == (char *)0x0) {
LAB_4542e882:
                        if (param_8 != (char *)0x0) {
                          *param_8 = '\0';
                        }
                        return 0;
                      }
                      if ((uint)((int)pcVar7 - (int)pcVar8) < param_7) {
                        FUN_454395bc(param_6,param_7,pcVar8,(int)pcVar7 - (int)pcVar8);
                        goto LAB_4542e882;
                      }
LAB_4542e890:
                      bVar2 = false;
                    }
                    else {
                      if (param_6 != (char *)0x0) {
                        if (param_7 <= (uint)((int)pcVar6 - (int)pcVar8)) goto LAB_4542e890;
                        FUN_454395bc(param_6,param_7,pcVar8,(int)pcVar6 - (int)pcVar8);
                      }
                      if (param_8 == (char *)0x0) {
                        return 0;
                      }
                      if ((uint)((int)pcVar7 - (int)pcVar6) < param_9) {
                        FUN_454395bc(param_8,param_9,pcVar6,(int)pcVar7 - (int)pcVar6);
                        return 0;
                      }
                    }
                    goto LAB_4542e8a7;
                  }
                }
                else if (param_9 != 0) goto LAB_4542e76f;
              }
            }
            else if (param_7 != 0) goto LAB_4542e75b;
          }
        }
        else if (param_5 != 0) goto LAB_4542e747;
      }
    }
    else if (param_3 != 0) goto LAB_4542e733;
  }
  bVar2 = true;
LAB_4542e8a7:
  if ((param_2 != (char *)0x0) && (param_3 != 0)) {
    *param_2 = '\0';
  }
  if ((param_4 != (char *)0x0) && (param_5 != 0)) {
    *param_4 = '\0';
  }
  if ((param_6 != (char *)0x0) && (param_7 != 0)) {
    *param_6 = '\0';
  }
  if ((param_8 != (char *)0x0) && (param_9 != 0)) {
    *param_8 = '\0';
  }
  piVar4 = __errno();
  if ((param_1 == (char *)0x0) || (bVar2)) {
    uVar5 = 0x16;
    *piVar4 = 0x16;
    FUN_45432798();
  }
  else {
    uVar5 = 0x22;
    *piVar4 = 0x22;
  }
  return uVar5;
}


