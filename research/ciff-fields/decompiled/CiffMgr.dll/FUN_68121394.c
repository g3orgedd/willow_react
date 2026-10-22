// Source: CiffMgr.dll @ 68121394; FUN_68121394

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_68121394(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR bstrString;
  wchar_t *local_20;
  BSTR local_1c;
  BSTR local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x10;
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
        local_20 = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_20);
        if (-1 < iVar2) {
          iVar3 = FUN_6812e15e(0x6815f9c0,local_20,0,8);
          if (iVar3 < 0x5b) {
            if (iVar3 == 0x5a) {
              local_18 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              bstrString = local_18;
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1,local_18);
                bstrString = local_18;
              }
            }
            else if (iVar3 == 0x10) {
              local_18 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              bstrString = local_18;
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*piVar1 + 0x70))(piVar1,local_18);
                bstrString = local_18;
              }
            }
            else if (iVar3 == 0x4d) {
              local_18 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              bstrString = local_18;
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                iVar3 = FUN_6812f116((ushort *)local_18);
                iVar2 = (**(code **)(iVar2 + 0x38))(piVar1,iVar3);
                bstrString = local_18;
              }
            }
            else if (iVar3 == 0x58) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              bstrString = local_18;
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                uVar4 = FUN_6812e988(local_18);
                iVar2 = (**(code **)(iVar2 + 0x40))(piVar1,uVar4);
                bstrString = local_18;
              }
            }
            else {
              if (iVar3 != 0x59) goto LAB_681215c4;
              local_18 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              bstrString = local_18;
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*piVar1 + 0x48))(piVar1,local_18);
                bstrString = local_18;
              }
            }
          }
          else if (iVar3 == 0x5b) {
            local_18 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
            bstrString = local_18;
            if (-1 < iVar2) {
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_18);
              iVar2 = (**(code **)(iVar2 + 0x60))(piVar1,iVar3);
              bstrString = local_18;
            }
          }
          else if (iVar3 == 0x5c) {
            local_18 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
            bstrString = local_18;
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*piVar1 + 0x58))(piVar1,local_18);
              bstrString = local_18;
            }
          }
          else if (iVar3 == 0x5d) {
            local_18 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
            bstrString = local_18;
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*piVar1 + 0x68))(piVar1,local_18);
              bstrString = local_18;
            }
          }
          else {
            if (iVar3 != 0x5e) goto LAB_681215c4;
            local_1c = (BSTR)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_1c);
            bstrString = local_1c;
            if (-1 < iVar2) {
              iVar2 = (**(code **)(*piVar1 + 0x78))(piVar1,local_1c);
              bstrString = local_1c;
            }
          }
          SysFreeString(bstrString);
        }
LAB_681215c4:
        SysFreeString(local_20);
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


