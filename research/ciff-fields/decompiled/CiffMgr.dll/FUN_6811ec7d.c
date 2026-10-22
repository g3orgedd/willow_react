// Source: CiffMgr.dll @ 6811ec7d; FUN_6811ec7d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811ec7d(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  wchar_t *local_28;
  BSTR local_24;
  int *local_20;
  wchar_t *local_1c;
  void *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_18 = this;
  if (*param_1 == 0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    do {
      local_14[0] = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,local_14);
      if ((iVar2 == 0) && (local_14[0] != (int *)0x0)) {
        local_28 = (wchar_t *)0x0;
        iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_28);
        if (-1 < iVar2) {
          iVar3 = FUN_6812e15e(0x6815fa48,local_28,0,8);
          if (iVar3 == 0x66) {
            local_24 = (BSTR)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*(int *)*param_1 + 0xd4))((int *)*param_1,local_24);
            }
          }
          else if (iVar3 == 0x67) {
            local_24 = (wchar_t *)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              piVar1 = (int *)*param_1;
              iVar2 = *piVar1;
              uVar4 = FUN_6812ef23(local_24);
              iVar2 = (**(code **)(iVar2 + 0xdc))(piVar1,uVar4);
            }
          }
          else if (iVar3 == 0x68) {
            local_24 = (BSTR)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              piVar1 = (int *)*param_1;
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_24);
              iVar2 = (**(code **)(iVar2 + 0xe4))(piVar1,iVar3);
            }
          }
          else if (iVar3 == 0x69) {
            local_24 = (BSTR)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              piVar1 = (int *)*param_1;
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_24);
              iVar2 = (**(code **)(iVar2 + 0xec))(piVar1,iVar3);
            }
          }
          else if (iVar3 == 0x6a) {
            local_24 = (BSTR)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              piVar1 = (int *)*param_1;
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_24);
              iVar2 = (**(code **)(iVar2 + 0x140))(piVar1,iVar3);
            }
          }
          else {
            if (iVar3 != 0x6b) {
              if (iVar3 == 0xc4) {
                CComQIPtr<>(&local_20,(undefined4 *)*param_1);
                local_8._0_1_ = 1;
                if (local_20 != (int *)0x0) {
                  local_1c = (wchar_t *)0x0;
                  iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_1c);
                  piVar1 = local_20;
                  if (-1 < iVar2) {
                    iVar2 = *local_20;
                    uVar4 = FUN_6812fa90(local_1c);
                    iVar2 = (**(code **)(iVar2 + 0x1a8))(piVar1,uVar4);
                  }
                  SysFreeString(local_1c);
                }
                local_8 = (uint)local_8._1_3_ << 8;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 8))(local_20);
                }
              }
              goto LAB_6811eec8;
            }
            local_24 = (BSTR)0x0;
            iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_24);
            if (-1 < iVar2) {
              piVar1 = (int *)*param_1;
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_24);
              iVar2 = (**(code **)(iVar2 + 0x148))(piVar1,iVar3);
            }
          }
          SysFreeString(local_24);
        }
LAB_6811eec8:
        SysFreeString(local_28);
      }
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


