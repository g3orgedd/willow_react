// Source: CLCSSmallBarcode.dll @ 420323e9; FUN_420323e9

int __fastcall FUN_420323e9(void *param_1)

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
LAB_42032406:
  do {
    do {
      if (local_6 != '\0') {
        return iVar6;
      }
      iVar3 = FUN_420319e3(param_1,&local_14);
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
                iVar6 = FUN_42031972(param_1,0x389);
                FUN_42069a00((undefined8 *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x37),
                             (undefined8 *)((int)param_1 + *(int *)((int)param_1 + 0xad0) + 0x36),
                             0xd);
                *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + 3;
                local_14 = local_14 - 3;
                cVar2 = local_5;
                goto LAB_4203274c;
              }
              uVar7 = 0x388;
            }
            else if (iVar4 == 2) {
              uVar7 = 0x38d;
            }
            else {
              if (iVar4 != 3) goto LAB_4203274c;
              uVar7 = 0x38f;
            }
            iVar6 = FUN_42031972(param_1,uVar7);
            cVar2 = local_5;
          }
          else if (iVar3 == 2) {
            iVar4 = *(int *)((int)param_1 + 0x1c);
            if (iVar4 == 0) goto LAB_420325f1;
            if (iVar4 == 1) {
              uVar7 = 0x387;
            }
            else if (iVar4 == 2) {
              uVar7 = 0x38c;
            }
            else {
              if (iVar4 != 3) goto LAB_4203274c;
              uVar7 = 0x38e;
            }
            iVar6 = FUN_42031972(param_1,uVar7);
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
LAB_420325f1:
              iVar6 = FUN_42031972(param_1,900);
              *(undefined4 *)((int)param_1 + 0x1218) = 1;
              cVar2 = local_5;
            }
            else if (((iVar3 == 3) && (*(int *)((int)param_1 + 0x1c) != 0)) && (local_14 == 1)) {
              iVar3 = *(int *)((int)param_1 + 0xad0);
              cVar1 = *(char *)(iVar3 + 0x34 + (int)param_1);
              if ((cVar1 == -0x6f) || (cVar1 == -0x6e)) {
LAB_42032593:
                *(int *)((int)param_1 + 0xad0) = iVar3 + 1;
                iVar5 = (cVar1 == -0x6e) + 4;
                cVar2 = '\x01';
              }
            }
          }
          else if (iVar4 == 2) {
            if (iVar3 == 1) {
              iVar6 = FUN_42031972(param_1,0x386);
              iVar5 = 1;
              cVar2 = local_5;
            }
            else {
              iVar5 = iVar4;
              if (iVar3 == 3) {
                if (*(int *)((int)param_1 + 0x1c) == 0) {
                  if (local_14 != 1) goto LAB_420325e4;
                }
                else {
                  if (local_14 != 1) {
LAB_420325e4:
                    iVar5 = 3;
                    goto LAB_4203274c;
                  }
                  iVar3 = *(int *)((int)param_1 + 0xad0);
                  cVar1 = *(char *)(iVar3 + 0x34 + (int)param_1);
                  if ((cVar1 == -0x6f) || (cVar1 == -0x6e)) goto LAB_42032593;
                }
                iVar6 = FUN_42031972(param_1,0x391);
                if (iVar6 == 0) {
                  iVar6 = FUN_42031972(param_1,(ushort)*(byte *)((int)param_1 +
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
              iVar6 = FUN_42031972(param_1,0x386);
              cVar2 = local_5;
            }
            else if (iVar3 == 2) {
              iVar6 = FUN_42031972(param_1,900);
              *(undefined4 *)((int)param_1 + 0x1218) = 1;
              cVar2 = local_5;
            }
          }
          else {
            iVar5 = iVar4;
            if (iVar4 - 4U < 2) {
              if (iVar3 == 1) {
                iVar6 = FUN_42031972(param_1,0x389);
                iVar5 = iVar3;
                cVar2 = local_5;
                if ((iVar4 == 5) && (-1 < iVar6)) {
                  iVar6 = FUN_42031972(param_1,0x389);
                  cVar2 = local_5;
                }
              }
              else if (iVar3 == 2) {
                FUN_420332d6(param_1,local_10,(undefined2 *)local_c,local_14);
                if ((local_c[0] & 4) == 0) {
LAB_420324e5:
                  iVar6 = FUN_42031972(param_1,0x387);
                  if ((iVar4 == 5) && (-1 < iVar6)) {
                    iVar6 = FUN_42031972(param_1,0x387);
                  }
                  *(undefined4 *)((int)param_1 + 0x1218) = 1;
                  iVar5 = iVar3;
                  cVar2 = local_5;
                }
                else {
                  iVar6 = FUN_42031972(param_1,0x388);
                  if ((iVar4 == 5) && (-1 < iVar6)) {
                    iVar6 = FUN_42031972(param_1,0x388);
                  }
                  *(undefined4 *)((int)param_1 + 0x1218) = 4;
                  iVar5 = iVar3;
                  cVar2 = local_5;
                }
              }
              else {
                iVar5 = iVar3;
                if (iVar3 == 3) goto LAB_420324e5;
              }
            }
          }
        }
      }
LAB_4203274c:
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar4 = iVar5;
    } while (cVar2 != '\0');
    if (iVar5 == 0) {
      iVar6 = FUN_42031df0(param_1);
      if (iVar6 == 0) {
        FUN_42032b6c(param_1);
      }
      local_6 = '\x01';
    }
    else if (iVar5 == 1) {
      iVar6 = FUN_4203318e(param_1,local_14);
    }
    else if (iVar5 == 2) {
      iVar6 = FUN_420333ab(param_1,local_14);
    }
    else {
      if (iVar5 != 3) {
        *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + local_14;
        goto LAB_42032406;
      }
      iVar6 = FUN_42031bfe(param_1,local_14);
    }
    if (iVar6 != 0) {
      return iVar6;
    }
  } while( true );
}


