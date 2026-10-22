// Source: CiffMgr.dll @ 6811a3ca; FUN_6811a3ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811a3ca(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_30;
  wchar_t *local_2c;
  int *local_28;
  wchar_t *local_24;
  int *local_20;
  wchar_t *local_1c;
  int *local_18 [4];
  int local_8;
  undefined4 uStack_4;
  
  piVar4 = param_1;
  uStack_4 = 0x20;
  local_8 = 0x6811a3d6;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 100))(param_1,&local_30);
    if (local_30 == 1) {
      local_18[0] = (int *)0x0;
      local_8 = 0;
      iVar1 = (**(code **)*piVar4)(piVar4,&DAT_6814a7fc,local_18);
      if ((-1 < iVar1) && (local_18[0] != (int *)0x0)) {
        do {
          param_1 = (int *)0x0;
          local_8._0_1_ = 1;
          iVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_1);
          if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
            local_2c = (wchar_t *)0x0;
            iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,&local_2c);
            if (-1 < iVar1) {
              iVar2 = FUN_6812e15e(0x6815fa90,local_2c,0,0x21);
              if (iVar2 < 0xba) {
                if (iVar2 < 0xb8) {
                  if (iVar2 < 0x76) {
                    if (iVar2 == 0x75) {
                      local_1c = (wchar_t *)0x0;
                      iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                      piVar4 = local_18[0];
                      if (-1 < iVar1) {
                        iVar1 = *local_18[0];
                        uVar3 = FUN_6812e988(local_1c);
                        iVar1 = (**(code **)(iVar1 + 0x10c))(piVar4,uVar3);
                      }
                    }
                    else if (iVar2 == 0x71) {
                      local_1c = (BSTR)0x0;
                      iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                      piVar4 = local_18[0];
                      if (-1 < iVar1) {
                        iVar1 = *local_18[0];
                        iVar2 = FUN_6812f116((ushort *)local_1c);
                        iVar1 = (**(code **)(iVar1 + 0xb4))(piVar4,iVar2);
                      }
                    }
                    else {
                      if (iVar2 != 0x72) {
                        if (iVar2 == 0x73) {
                          iVar1 = FUN_6811f5a7((int *)local_18,(BSTR)&param_1);
                        }
                        else if (iVar2 == 0x74) {
                          local_1c = (wchar_t *)0x0;
                          iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                          piVar4 = local_18[0];
                          if (-1 < iVar1) {
                            iVar1 = *local_18[0];
                            uVar3 = FUN_6812e988(local_1c);
                            iVar1 = (**(code **)(iVar1 + 0x104))(piVar4,uVar3);
                          }
                          goto LAB_6811a575;
                        }
                        goto switchD_6811a661_caseD_cb;
                      }
                      local_1c = (BSTR)0x0;
                      iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                      piVar4 = local_18[0];
                      if (-1 < iVar1) {
                        iVar1 = *local_18[0];
                        iVar2 = FUN_6812f116((ushort *)local_1c);
                        iVar1 = (**(code **)(iVar1 + 0xbc))(piVar4,iVar2);
                      }
                    }
                  }
                  else {
                    if (iVar2 != 0x76) {
                      if ((iVar2 < 0x77) || ((0x85 < iVar2 && (iVar2 != 0xb4))))
                      goto switchD_6811a661_caseD_cb;
                      goto switchD_6811a661_caseD_ca;
                    }
                    local_1c = (BSTR)0x0;
                    iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                    piVar4 = local_18[0];
                    if (-1 < iVar1) {
                      iVar1 = *local_18[0];
                      iVar2 = FUN_6812f116((ushort *)local_1c);
                      iVar1 = (**(code **)(iVar1 + 0x150))(piVar4,iVar2);
                    }
                  }
LAB_6811a575:
                  SysFreeString(local_1c);
                }
                else {
switchD_6811a661_caseD_ca:
                  iVar1 = FUN_6811a75a((BSTR)local_18,(int *)&param_1);
                }
              }
              else {
                switch(iVar2) {
                case 0xca:
                case 0xce:
                case 0xcf:
                case 0xde:
                case 0xe2:
                case 0xe3:
                case 0xe4:
                case 0xe5:
                case 0xed:
                  goto switchD_6811a661_caseD_ca;
                default:
                  goto switchD_6811a661_caseD_cb;
                case 0xdd:
                  CComQIPtr<>(&local_20,local_18[0]);
                  local_8._0_1_ = 2;
                  piVar4 = local_20;
                  if (local_20 != (int *)0x0) {
                    local_1c = (BSTR)0x0;
                    iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
                    piVar4 = local_20;
                    if (-1 < iVar1) {
                      iVar1 = *local_20;
                      iVar2 = FUN_6812f116((ushort *)local_1c);
                      iVar1 = (**(code **)(iVar1 + 0x1f0))(piVar4,iVar2);
                    }
                    SysFreeString(local_1c);
                    piVar4 = local_20;
                  }
                  break;
                case 0xe7:
                  CComQIPtr<>(&local_28,local_18[0]);
                  local_8._0_1_ = 3;
                  piVar4 = local_28;
                  if (local_28 != (int *)0x0) {
                    local_24 = (wchar_t *)0x0;
                    iVar1 = (**(code **)(*param_1 + 0x68))(param_1,&local_24);
                    piVar4 = local_28;
                    if (-1 < iVar1) {
                      iVar1 = *local_28;
                      uVar3 = FUN_6812e8ba(local_24);
                      iVar1 = (**(code **)(iVar1 + 0x210))(piVar4,uVar3);
                    }
                    SysFreeString(local_24);
                    piVar4 = local_28;
                  }
                }
                local_8._0_1_ = 1;
                if (piVar4 != (int *)0x0) {
                  (**(code **)(*piVar4 + 8))(piVar4);
                }
              }
            }
switchD_6811a661_caseD_cb:
            SysFreeString(local_2c);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        } while (iVar1 == 0);
        if (iVar1 == 1) {
          iVar1 = 0;
        }
      }
      local_8 = 0xffffffff;
      if (local_18[0] != (int *)0x0) {
        (**(code **)(*local_18[0] + 8))(local_18[0]);
      }
    }
    else {
      iVar1 = -0x7ff8ffa9;
    }
  }
  return iVar1;
}


