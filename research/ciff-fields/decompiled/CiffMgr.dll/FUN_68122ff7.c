// Source: CiffMgr.dll @ 68122ff7; FUN_68122ff7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_68122ff7(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  code *pcVar6;
  wchar_t *local_2c;
  int *local_28;
  int *local_24;
  ushort *local_20;
  int *local_1c;
  wchar_t *local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x1c;
  pcVar6 = SysFreeString_exref;
  local_14 = this;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    do {
      param_1 = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_2c = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_2c);
        if (-1 < iVar2) {
          iVar3 = FUN_6812e15e(0x6815fa48,local_2c,0,8);
          if (iVar3 < 0x6b) {
            if (iVar3 == 0x6a) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                iVar3 = FUN_6812f116((ushort *)local_18);
                iVar2 = (**(code **)(iVar2 + 0x120))(piVar1,iVar3);
              }
            }
            else if (iVar3 == 0x66) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*piVar1 + 0xac))(piVar1,local_18);
              }
            }
            else if (iVar3 == 0x67) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                uVar4 = FUN_6812ef23(local_18);
                iVar2 = (**(code **)(iVar2 + 0x100))(piVar1,uVar4);
              }
            }
            else if (iVar3 == 0x68) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                iVar3 = FUN_6812f116((ushort *)local_18);
                iVar2 = (**(code **)(iVar2 + 0xb4))(piVar1,iVar3);
              }
            }
            else {
              if (iVar3 != 0x69) goto LAB_68123302;
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                iVar3 = FUN_6812f116((ushort *)local_18);
                iVar2 = (**(code **)(iVar2 + 0xbc))(piVar1,iVar3);
              }
            }
          }
          else {
            if (iVar3 != 0x6b) {
              if (iVar3 == 0xc4) {
                CComQIPtr<>(&local_28,piVar1);
                local_8._0_1_ = 2;
                piVar5 = local_28;
                if (local_28 != (int *)0x0) {
                  local_18 = (wchar_t *)0x0;
                  iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                  piVar5 = local_28;
                  if (-1 < iVar2) {
                    iVar2 = *local_28;
                    uVar4 = FUN_6812fa90(local_18);
                    iVar2 = (**(code **)(iVar2 + 0x138))(piVar5,uVar4);
                    pcVar6 = SysFreeString_exref;
                  }
                  (*pcVar6)(local_18);
                  piVar5 = local_28;
                }
              }
              else if (iVar3 == 200) {
                CComQIPtr<>(&local_24,piVar1);
                local_8._0_1_ = 3;
                piVar5 = local_24;
                if (local_24 != (int *)0x0) {
                  local_20 = (ushort *)0x0;
                  iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
                  piVar5 = local_24;
                  if (-1 < iVar2) {
                    iVar2 = *local_24;
                    iVar3 = FUN_6812f116(local_20);
                    iVar2 = (**(code **)(iVar2 + 0x154))(piVar5,iVar3);
                    pcVar6 = SysFreeString_exref;
                  }
                  (*pcVar6)(local_20);
                  piVar5 = local_24;
                }
              }
              else {
                if (iVar3 != 0xda) goto LAB_68123302;
                CComQIPtr<>(&local_1c,piVar1);
                local_8._0_1_ = 1;
                piVar5 = local_1c;
                if (local_1c != (int *)0x0) {
                  local_18 = (wchar_t *)0x0;
                  iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                  piVar5 = local_1c;
                  if (-1 < iVar2) {
                    iVar2 = *local_1c;
                    iVar3 = FUN_6812f116((ushort *)local_18);
                    iVar2 = (**(code **)(iVar2 + 0x16c))(piVar5,iVar3);
                    pcVar6 = SysFreeString_exref;
                  }
                  (*pcVar6)(local_18);
                  piVar5 = local_1c;
                }
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (piVar5 != (int *)0x0) {
                (**(code **)(*piVar5 + 8))(piVar5);
              }
              goto LAB_68123302;
            }
            local_18 = (wchar_t *)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
            if (-1 < iVar2) {
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_18);
              iVar2 = (**(code **)(iVar2 + 0x128))(piVar1,iVar3);
            }
          }
          (*pcVar6)(local_18);
        }
LAB_68123302:
        (*pcVar6)(local_2c);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


