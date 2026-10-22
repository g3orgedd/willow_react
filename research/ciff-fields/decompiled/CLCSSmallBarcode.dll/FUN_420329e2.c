// Source: CLCSSmallBarcode.dll @ 420329e2; FUN_420329e2

int __fastcall FUN_420329e2(void *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  uint local_10;
  int local_c;
  char local_6;
  char local_5;
  
  local_10 = 0;
  local_c = 0;
  local_6 = '\0';
  iVar3 = FUN_42031972(param_1,0);
  *(undefined4 *)((int)param_1 + 0xad0) = 0;
  cVar5 = '\0';
LAB_42032a0b:
  do {
    if (iVar3 != 0) {
      return iVar3;
    }
LAB_42032a1b:
    do {
      if (cVar5 != '\0') {
        return iVar3;
      }
      iVar4 = FUN_420319e3(param_1,&local_10);
      local_5 = '\0';
      if (iVar4 == 0) {
        local_c = 0;
        cVar2 = '\0';
        iVar1 = local_c;
      }
      else {
        cVar2 = local_5;
        iVar1 = iVar4;
        if (local_c == 0) {
          if (iVar4 == 1) {
LAB_42032a57:
            iVar3 = FUN_42031972(param_1,0x386);
            cVar2 = local_5;
            iVar1 = iVar4;
          }
        }
        else if (local_c == 1) {
LAB_42032a65:
          iVar1 = iVar4;
          if (iVar4 == 2) {
            iVar3 = FUN_42031972(param_1,900);
            *(undefined4 *)((int)param_1 + 0x1218) = 1;
            cVar2 = local_5;
          }
        }
        else if (local_c == 2) {
          if (iVar4 == 1) {
            iVar3 = FUN_42031972(param_1,0x386);
            cVar2 = local_5;
          }
          else {
            iVar1 = local_c;
            if (iVar4 == 3) {
              if (local_10 == 1) {
                iVar3 = FUN_42031972(param_1,0x391);
                if (iVar3 == 0) {
                  iVar3 = FUN_42031972(param_1,(ushort)*(byte *)((int)param_1 +
                                                                *(int *)((int)param_1 + 0xad0) +
                                                                0x34));
                  *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + 1;
                }
                cVar2 = '\x01';
                iVar1 = local_c;
              }
              else {
                local_c = 3;
                cVar2 = '\0';
                iVar1 = local_c;
              }
            }
          }
        }
        else {
          iVar1 = local_c;
          if (local_c == 3) {
            if (iVar4 == 1) goto LAB_42032a57;
            goto LAB_42032a65;
          }
        }
      }
      local_c = iVar1;
      if (iVar3 != 0) {
        return iVar3;
      }
      cVar5 = local_6;
    } while (cVar2 != '\0');
    if (local_c == 0) {
      iVar3 = FUN_42031df0(param_1);
      if (iVar3 == 0) {
        FUN_42032b6c(param_1);
      }
      local_6 = '\x01';
      cVar5 = '\x01';
      goto LAB_42032a0b;
    }
    if (local_c == 1) {
      iVar3 = FUN_4203318e(param_1,local_10);
      cVar5 = local_6;
      goto LAB_42032a0b;
    }
    if (local_c == 2) {
      iVar3 = FUN_420333ab(param_1,local_10);
      cVar5 = local_6;
      goto LAB_42032a0b;
    }
    if (local_c != 3) {
      *(int *)((int)param_1 + 0xad0) = *(int *)((int)param_1 + 0xad0) + local_10;
      goto LAB_42032a1b;
    }
    iVar3 = FUN_42031bfe(param_1,local_10);
    cVar5 = local_6;
  } while( true );
}


