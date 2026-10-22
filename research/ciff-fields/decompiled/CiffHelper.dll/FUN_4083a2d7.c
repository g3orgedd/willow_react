// Source: CiffHelper.dll @ 4083a2d7; FUN_4083a2d7

void __cdecl FUN_4083a2d7(double *param_1,undefined8 *param_2,double *param_3,int param_4)

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
  if (DAT_40866a84 == 0) {
    pcVar1 = FUN_4081d67d;
  }
  else {
    pcVar1 = DecodePointer(DAT_40868590);
  }
  if (param_4 < 0xa7) {
    if (param_4 == 0xa6) {
      local_2c = 3;
      local_28 = "exp10";
LAB_4083a36d:
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
          if (param_4 == 0x1c) goto switchD_4083a4bd_caseD_3ee;
          if (param_4 != 0x1d) {
            if (param_4 == 0x31) goto switchD_4083a4bd_caseD_3f5;
            if (param_4 != 0x3a) {
              if (param_4 != 0x3d) {
                return;
              }
              goto switchD_4083a4bd_caseD_3f1;
            }
            goto switchD_4083a4bd_caseD_3f0;
          }
          local_28 = "pow";
          goto LAB_4083a469;
        }
        local_2c = 2;
LAB_4083a366:
        local_28 = "pow";
        goto LAB_4083a36d;
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
            goto LAB_4083a54e;
          }
          if (param_4 == 8) {
            local_28 = "log10";
          }
          else {
            if (param_4 == 9) {
              local_28 = "log10";
              goto LAB_4083a54e;
            }
            if (param_4 != 0xe) {
              if (param_4 != 0xf) {
                if (param_4 != 0x18) {
                  return;
                }
                local_2c = 3;
                goto LAB_4083a366;
              }
              local_28 = "exp";
              goto LAB_4083a3ab;
            }
            local_2c = 3;
            local_28 = "exp";
          }
        }
        goto LAB_4083a36d;
      }
      local_28 = "pow";
LAB_4083a3ab:
      local_2c = 4;
      local_24 = *param_1;
      local_1c = *param_2;
      local_14 = *param_3;
      (*pcVar1)(&local_2c);
    }
    goto LAB_4083a57d;
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
switchD_4083a4bd_caseD_3ee:
    local_28 = "pow";
    goto LAB_4083a54e;
  case 0x3ef:
    local_28 = "modf";
    break;
  case 0x3f0:
switchD_4083a4bd_caseD_3f0:
    local_28 = "acos";
    goto LAB_4083a54e;
  case 0x3f1:
switchD_4083a4bd_caseD_3f1:
    local_28 = "asin";
    goto LAB_4083a54e;
  case 0x3f2:
    local_28 = "sin";
    goto LAB_4083a513;
  case 0x3f3:
    local_28 = "cos";
    goto LAB_4083a513;
  case 0x3f4:
    local_28 = "tan";
LAB_4083a513:
    local_14 = *param_1 * (double)CONCAT44(uStack_8,local_c);
    *param_3 = local_14;
    local_24 = *param_1;
    local_1c = *param_2;
    goto LAB_4083a55d;
  case 0x3f5:
switchD_4083a4bd_caseD_3f5:
    local_28 = "sqrt";
    goto LAB_4083a54e;
  default:
    goto switchD_4083a4bd_default;
  }
LAB_4083a469:
  *param_3 = *param_1;
LAB_4083a54e:
  local_24 = *param_1;
  local_1c = *param_2;
  local_14 = *param_3;
LAB_4083a55d:
  local_2c = 1;
  iVar2 = (*pcVar1)(&local_2c);
  if (iVar2 == 0) {
    piVar3 = __errno();
    *piVar3 = 0x21;
  }
LAB_4083a57d:
  *param_3 = local_14;
switchD_4083a4bd_default:
  return;
}


