// Source: CiffMgr.dll @ 68120227; FUN_68120227

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_68120227(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  _union_2683 *pvarg;
  bool bVar5;
  BSTR bstrString;
  _union_2683 local_44;
  _union_2683 local_34;
  wchar_t *local_24;
  BSTR local_20;
  int *local_1c;
  BSTR local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x34;
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
        local_24 = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_24);
        if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
          local_1c = (int *)0x0;
          local_8._0_1_ = 1;
          iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_1c);
          iVar3 = FUN_6812e15e(0x6815fbe8,local_24,0,9);
          if (iVar3 < 0xa6) {
            if (iVar3 == 0xa5) {
              local_18 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                iVar3 = FUN_6812f116((ushort *)local_18);
                iVar2 = (**(code **)(iVar2 + 0x38))(piVar1,iVar3);
              }
              SysFreeString(local_18);
              if (local_1c != (int *)0x0) {
                local_18 = (BSTR)0x0;
                local_8._0_1_ = 4;
                iVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Used_68160040,&local_18);
                if (iVar2 == 0) {
                  bVar5 = true;
                  if (local_18 == (BSTR)0x0) goto LAB_68120620;
                  FUN_68132710((uint *)&local_34,0,0x10);
                  VariantInit((VARIANTARG *)&local_34.n2);
                  local_8._0_1_ = 5;
                  iVar2 = (**(code **)(*(int *)local_18 + 0x20))(local_18,&local_34);
                  if (local_34.n2.vt == 8) {
                    iVar2 = *piVar1;
                    iVar3 = FUN_6812f116((ushort *)local_34._8_4_);
                    iVar2 = (**(code **)(iVar2 + 0x40))(piVar1,iVar3);
                  }
                  pvarg = &local_34;
LAB_68120614:
                  VariantClear((VARIANTARG *)&pvarg->n2);
                }
LAB_6812061e:
                bVar5 = local_18 == (BSTR)0x0;
LAB_68120620:
                local_8._0_1_ = 1;
                if (!bVar5) {
                  (**(code **)(*(int *)local_18 + 8))(local_18);
                }
              }
            }
            else {
              if (iVar3 == 0x10) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*piVar1 + 0x90))(piVar1,local_18);
                  bstrString = local_18;
                }
              }
              else if (iVar3 == 0x11) {
                local_18 = (wchar_t *)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = *piVar1;
                  uVar4 = FUN_6812f499(local_18);
                  iVar2 = (**(code **)(iVar2 + 0x88))(piVar1,uVar4);
                  bstrString = local_18;
                }
              }
              else if (iVar3 == 0x1c) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*piVar1 + 0x68))(piVar1,local_18);
                  bstrString = local_18;
                }
              }
              else if (iVar3 == 0x43) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_18);
                  iVar2 = (**(code **)(iVar2 + 0x28))(piVar1,iVar3);
                  bstrString = local_18;
                }
              }
              else {
                if (iVar3 != 0xa4) goto LAB_6812062c;
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_18);
                  iVar2 = (**(code **)(iVar2 + 0x30))(piVar1,iVar3);
                  bstrString = local_18;
                }
              }
LAB_68120326:
              SysFreeString(bstrString);
            }
          }
          else {
            if (iVar3 != 0xa6) {
              if (iVar3 == 0xa7) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_18);
                  iVar2 = (**(code **)(iVar2 + 0x80))(piVar1,iVar3);
                  bstrString = local_18;
                }
              }
              else if (iVar3 == 0xa8) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_18);
                  iVar2 = (**(code **)(iVar2 + 0x58))(piVar1,iVar3);
                  bstrString = local_18;
                }
              }
              else if (iVar3 == 0xa9) {
                local_18 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
                bstrString = local_18;
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,local_18);
                  bstrString = local_18;
                }
              }
              else {
                if (iVar3 != 0xaa) goto LAB_6812062c;
                local_20 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
                bstrString = local_20;
                if (-1 < iVar2) {
                  iVar2 = (**(code **)(*piVar1 + 0x70))(piVar1,local_20);
                  bstrString = local_20;
                }
              }
              goto LAB_68120326;
            }
            local_18 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_18);
            if (-1 < iVar2) {
              iVar2 = *piVar1;
              iVar3 = FUN_6812f116((ushort *)local_18);
              iVar2 = (**(code **)(iVar2 + 0x48))(piVar1,iVar3);
            }
            SysFreeString(local_18);
            if (local_1c != (int *)0x0) {
              local_18 = (BSTR)0x0;
              local_8._0_1_ = 2;
              iVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Used_68160040,&local_18);
              if (iVar2 != 0) goto LAB_6812061e;
              bVar5 = local_18 == (BSTR)0x0;
              if (!bVar5) {
                FUN_68132710((uint *)&local_44,0,0x10);
                VariantInit((VARIANTARG *)&local_44.n2);
                local_8._0_1_ = 3;
                iVar2 = (**(code **)(*(int *)local_18 + 0x20))(local_18,&local_44);
                if (local_44.n2.vt == 8) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_44._8_4_);
                  iVar2 = (**(code **)(iVar2 + 0x50))(piVar1,iVar3);
                }
                pvarg = &local_44;
                goto LAB_68120614;
              }
              goto LAB_68120620;
            }
          }
LAB_6812062c:
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
        SysFreeString(local_24);
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


