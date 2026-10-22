// Source: CLCiffConversion_Layout.dll @ 4542fb9c; FUN_4542fb9c

void __cdecl FUN_4542fb9c(double *param_1,undefined8 *param_2,double *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_2c;
  char *local_28;
  double local_24;
  undefined8 local_1c;
  double local_14;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = 0;
  if (DAT_45460b88 == 0) {
    pcVar1 = FUN_4543ab73;
  }
  else {
    pcVar1 = DecodePointer(DAT_4546279c);
  }
  if (param_4 < 0xa7) {
    if (param_4 == 0xa6) {
      local_2c = 3;
      local_28 = "exp10";
LAB_4542fc32:
      local_24 = *param_1;
      local_1c = *param_2;
      local_14 = *param_3;
      iVar2 = (*pcVar1)(&local_2c);
      if (iVar2 == 0) {
        piVar3 = __errno();
        *piVar3 = 0x22;
      }
    }
    else {
      if (0x19 < param_4) {
        if (param_4 == 0x1a) {
          *param_3 = 1.0;
          return;
        }
        if (param_4 != 0x1b) {
          if (param_4 == 0x1c) goto switchD_4542fd82_caseD_3ee;
          if (param_4 != 0x1d) {
            if (param_4 == 0x31) goto switchD_4542fd82_caseD_3f5;
            if (param_4 != 0x3a) {
              if (param_4 != 0x3d) {
                return;
              }
              goto switchD_4542fd82_caseD_3f1;
            }
            goto switchD_4542fd82_caseD_3f0;
          }
          local_28 = "pow";
          goto LAB_4542fd2e;
        }
        local_2c = 2;
LAB_4542fc2b:
        local_28 = "pow";
        goto LAB_4542fc32;
      }
      if (param_4 != 0x19) {
        local_2c = 2;
        if (param_4 == 2) {
          local_2c = 2;
          local_28 = "log";
        }
        else {
          if (param_4 == 3) {
            local_28 = "log";
            goto LAB_4542fe13;
          }
          if (param_4 == 8) {
            local_28 = "log10";
          }
          else {
            if (param_4 == 9) {
              local_28 = "log10";
              goto LAB_4542fe13;
            }
            if (param_4 != 0xe) {
              if (param_4 != 0xf) {
                if (param_4 != 0x18) {
                  return;
                }
                local_2c = 3;
                goto LAB_4542fc2b;
              }
              local_28 = "exp";
              goto LAB_4542fc70;
            }
            local_2c = 3;
            local_28 = "exp";
          }
        }
        goto LAB_4542fc32;
      }
      local_28 = "pow";
LAB_4542fc70:
      local_2c = 4;
      local_24 = *param_1;
      local_1c = *param_2;
      local_14 = *param_3;
      (*pcVar1)(&local_2c);
    }
    goto LAB_4542fe42;
  }
  switch(param_4) {
  case 1000:
    local_28 = "log";
    break;
  case 0x3e9:
    local_28 = "log10";
    break;
  case 0x3ea:
    local_28 = "exp";
    break;
  case 0x3eb:
    local_28 = "atan";
    break;
  case 0x3ec:
    local_28 = "ceil";
    break;
  case 0x3ed:
    local_28 = "floor";
    break;
  case 0x3ee:
switchD_4542fd82_caseD_3ee:
    local_28 = "pow";
    goto LAB_4542fe13;
  case 0x3ef:
    local_28 = "modf";
    break;
  case 0x3f0:
switchD_4542fd82_caseD_3f0:
    local_28 = "acos";
    goto LAB_4542fe13;
  case 0x3f1:
switchD_4542fd82_caseD_3f1:
    local_28 = "asin";
    goto LAB_4542fe13;
  case 0x3f2:
    local_28 = "sin";
    goto LAB_4542fdd8;
  case 0x3f3:
    local_28 = "cos";
    goto LAB_4542fdd8;
  case 0x3f4:
    local_28 = "tan";
LAB_4542fdd8:
    local_14 = *param_1 * (double)CONCAT44(uStack_8,local_c);
    *param_3 = local_14;
    local_24 = *param_1;
    local_1c = *param_2;
    goto LAB_4542fe22;
  case 0x3f5:
switchD_4542fd82_caseD_3f5:
    local_28 = "sqrt";
    goto LAB_4542fe13;
  default:
    goto switchD_4542fd82_default;
  }
LAB_4542fd2e:
  *param_3 = *param_1;
LAB_4542fe13:
  local_24 = *param_1;
  local_1c = *param_2;
  local_14 = *param_3;
LAB_4542fe22:
  local_2c = 1;
  iVar2 = (*pcVar1)(&local_2c);
  if (iVar2 == 0) {
    piVar3 = __errno();
    *piVar3 = 0x21;
  }
LAB_4542fe42:
  *param_3 = local_14;
switchD_4542fd82_default:
  return;
}


