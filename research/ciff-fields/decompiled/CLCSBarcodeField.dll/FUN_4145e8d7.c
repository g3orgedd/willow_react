// Source: CLCSBarcodeField.dll @ 4145e8d7; FUN_4145e8d7

int __fastcall FUN_4145e8d7(void *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint local_14;
  undefined2 local_10 [2];
  byte local_c [6];
  char local_6;
  char local_5;
  
  iVar6 = 0;
  local_6 = '\0';
  local_14 = 0;
  *(undefined4 *)((int)param_1 + 0xad0) = 0;
  iVar4 = 0;
LAB_4145e8f4:
  do {
    do {
      if (local_6 != '\0') {
        return iVar6;
      }
      iVar3 = FUN_4145ded1(param_1,&local_14);
      cVar2 = '\0';
      local_5 = '\0';
      if (iVar3 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = iVar3;
        if (iVar4 == 0) {
          if (iVar3 == 1) {
            iVar4 = *(int *)((int)param_1 + 0x1c);
            if (iVar4 == 0) {
              uVar7 = 0x386;
            }
            else if (iVar4 == 1) {
              if (((0xf < local_14) &&
                  (*(char *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x34) == '0')) &&
                 (*(char *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x35) == '1')) {
                iVar6 = FUN_4145de60(param_1,0x389);
                FUN_41460d10((undefined8 *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x37),
                             (undefined8 *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x36),
                             0xd);
                *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + 3;
                local_14 = local_14 - 3;
                cVar2 = local_5;
                goto LAB_4145ec3a;
              }
              uVar7 = 0x388;
            }
            else if (iVar4 == 2) {
              uVar7 = 0x38d;
            }
            else {
              if (iVar4 != 3) goto LAB_4145ec3a;
              uVar7 = 0x38f;
            }
            iVar6 = FUN_4145de60(param_1,uVar7);
            cVar2 = local_5;
          }
          else if (iVar3 == 2) {
            iVar4 = *(int *)((int)param_1 + 0x1c);
            if (iVar4 == 0) goto LAB_4145eadf;
            if (iVar4 == 1) {
              uVar7 = 0x387;
            }
            else if (iVar4 == 2) {
              uVar7 = 0x38c;
            }
            else {
              if (iVar4 != 3) goto LAB_4145ec3a;
              uVar7 = 0x38e;
            }
            iVar6 = FUN_4145de60(param_1,uVar7);
            *(undefined4 *)((int)param_1 + 0x1218) = 4;
            cVar2 = local_5;
          }
          else if ((((iVar3 == 3) && (*(int *)((int)param_1 + 0xad0) == 0)) &&
                   (*(int *)((int)param_1 + 0x1c) != 0)) &&
                  ((local_14 == 1 && (*(char *)((int)param_1 + 0x34) == -0x6f)))) {
            *(undefined4 *)((int)param_1 + 0xad0) = 1;
            iVar5 = 0;
            cVar2 = '\x01';
          }
        }
        else {
          cVar2 = local_5;
          if (iVar4 == 1) {
            if (iVar3 == 2) {
LAB_4145eadf:
              iVar6 = FUN_4145de60(param_1,900);
              *(undefined4 *)((int)param_1 + 0x1218) = 1;
              cVar2 = local_5;
            }
            else if (((iVar3 == 3) && (*(int *)((int)param_1 + 0x1c) != 0)) && (local_14 == 1)) {
              iVar3 = *(int *)((int)param_1 + 0xad0);
              cVar1 = *(char *)(iVar3 + 0x34 + (int)param_1);
              if ((cVar1 == -0x6f) || (cVar1 == -0x6e)) {
LAB_4145ea81:
                *(int *)((int)param_1 + 0xad0) = iVar3 + 1;
                iVar5 = (cVar1 == -0x6e) + 4;
                cVar2 = '\x01';
              }
            }
          }
          else if (iVar4 == 2) {
            if (iVar3 == 1) {
              iVar6 = FUN_4145de60(param_1,0x386);
              iVar5 = 1;
              cVar2 = local_5;
            }
            else {
              iVar5 = iVar4;
              if (iVar3 == 3) {
                if (*(int *)((int)param_1 + 0x1c) == 0) {
                  if (local_14 != 1) goto LAB_4145ead2;
                }
                else {
                  if (local_14 != 1) {
LAB_4145ead2:
                    iVar5 = 3;
                    goto LAB_4145ec3a;
                  }
                  iVar3 = *(int *)((int)param_1 + 0xad0);
                  cVar1 = *(char *)(iVar3 + 0x34 + (int)param_1);
                  if ((cVar1 == -0x6f) || (cVar1 == -0x6e)) goto LAB_4145ea81;
                }
                iVar6 = FUN_4145de60(param_1,0x391);
                if (iVar6 == 0) {
                  iVar6 = FUN_4145de60(param_1,(ushort)*(byte *)((int)param_1 +
                                                                *(int *)((int)param_1 + 0xad0) +
                                                                0x34));
                  *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + 1;
                }
                cVar2 = '\x01';
              }
            }
          }
          else if (iVar4 == 3) {
            if (iVar3 == 1) {
              iVar6 = FUN_4145de60(param_1,0x386);
              cVar2 = local_5;
            }
            else if (iVar3 == 2) {
              iVar6 = FUN_4145de60(param_1,900);
              *(undefined4 *)((int)param_1 + 0x1218) = 1;
              cVar2 = local_5;
            }
          }
          else {
            iVar5 = iVar4;
            if (iVar4 - 4U < 2) {
              if (iVar3 == 1) {
                iVar6 = FUN_4145de60(param_1,0x389);
                iVar5 = iVar3;
                cVar2 = local_5;
                if ((iVar4 == 5) && (-1 < iVar6)) {
                  iVar6 = FUN_4145de60(param_1,0x389);
                  cVar2 = local_5;
                }
              }
              else if (iVar3 == 2) {
                FUN_4145f7c4(param_1,local_10,(undefined2 *)local_c,local_14);
                if ((local_c[0] & 4) == 0) {
LAB_4145e9d3:
                  iVar6 = FUN_4145de60(param_1,0x387);
                  if ((iVar4 == 5) && (-1 < iVar6)) {
                    iVar6 = FUN_4145de60(param_1,0x387);
                  }
                  *(undefined4 *)((int)param_1 + 0x1218) = 1;
                  iVar5 = iVar3;
                  cVar2 = local_5;
                }
                else {
                  iVar6 = FUN_4145de60(param_1,0x388);
                  if ((iVar4 == 5) && (-1 < iVar6)) {
                    iVar6 = FUN_4145de60(param_1,0x388);
                  }
                  *(undefined4 *)((int)param_1 + 0x1218) = 4;
                  iVar5 = iVar3;
                  cVar2 = local_5;
                }
              }
              else {
                iVar5 = iVar3;
                if (iVar3 == 3) goto LAB_4145e9d3;
              }
            }
          }
        }
      }
LAB_4145ec3a:
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar4 = iVar5;
    } while (cVar2 != '\0');
    if (iVar5 == 0) {
      iVar6 = FUN_4145e2de(param_1);
      if (iVar6 == 0) {
        FUN_4145f05a(param_1);
      }
      local_6 = '\x01';
    }
    else if (iVar5 == 1) {
      iVar6 = FUN_4145f67c(param_1,local_14);
    }
    else if (iVar5 == 2) {
      iVar6 = FUN_4145f899(param_1,local_14);
    }
    else {
      if (iVar5 != 3) {
        *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + local_14;
        goto LAB_4145e8f4;
      }
      iVar6 = FUN_4145e0ec(param_1,local_14);
    }
    if (iVar6 != 0) {
      return iVar6;
    }
  } while( true );
}


