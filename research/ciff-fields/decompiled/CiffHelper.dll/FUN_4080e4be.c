// Source: CiffHelper.dll @ 4080e4be; FUN_4080e4be

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_4080e4be(void *this,int *param_1)

{
  BSTR pOVar1;
  int iVar2;
  UINT UVar3;
  BSTR pOVar4;
  uint uVar5;
  OLECHAR *******pppppppOVar6;
  uint uVar7;
  int local_60;
  int local_5c;
  int local_58;
  int local_54 [2];
  BSTR local_4c;
  BSTR local_48;
  WCHAR local_44 [12];
  OLECHAR *******local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_58 = 0;
  local_8 = 0;
  (**(code **)(*param_1 + 0x38))(param_1,&local_58);
  local_48 = (BSTR)0x0;
  local_8._0_1_ = 1;
  iVar2 = (**(code **)(*param_1 + 0x58))(param_1,&local_48);
  if ((((-1 < iVar2) && (*(wchar_t **)((int)this + 0x88) == L"StaticGraphic")) &&
      (local_48 != (BSTR)0x0)) && (UVar3 = SysStringLen(local_48), UVar3 != 0)) {
    basic_string<>(local_44,local_48);
    local_18 = 7;
    local_1c = 0;
    local_2c[0] = (OLECHAR *******)((uint)local_2c[0] & 0xffff0000);
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar2 = FUN_408094a5(local_44,(LPCWSTR)local_2c);
    if (-1 < iVar2) {
      pppppppOVar6 = (OLECHAR *******)local_2c;
      if (7 < local_18) {
        pppppppOVar6 = local_2c[0];
      }
      FUN_40803e97(&local_48,(OLECHAR *)pppppppOVar6);
    }
    FUN_4080653d(local_2c,'\x01',0);
    local_8._0_1_ = 1;
    FUN_4080653d(local_44,'\x01',0);
  }
  local_54[0] = 0;
  iVar2 = (**(code **)(*param_1 + 0x28))(param_1,local_54);
  if ((-1 < iVar2) && (local_58 == 0)) {
    if (local_54[0] == 3) {
      local_4c = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar2 = (**(code **)(*param_1 + 0xcc))(param_1,&local_4c);
      if (-1 < iVar2) {
        FUN_40803e5b(&local_48,(int *)&local_4c);
        (**(code **)(*param_1 + 0xd0))(param_1,local_48);
      }
      local_8._0_1_ = 1;
      SysFreeString(local_4c);
    }
    local_60 = 0;
    iVar2 = (**(code **)(*param_1 + 0x9c))(param_1,&local_60);
    if ((-1 < iVar2) && (local_60 != 0)) {
      local_4c = (BSTR)0x0;
      iVar2 = (**(code **)(*param_1 + 0x94))(param_1,&local_4c);
      pOVar4 = (BSTR)SysStringLen(local_48);
      if ((-1 < iVar2) && (pOVar4 < local_4c)) {
        local_54[1] = 0;
        iVar2 = (**(code **)(*param_1 + 0xa4))(param_1,local_54 + 1);
        pOVar1 = local_48;
        if (-1 < iVar2) {
          local_18 = 7;
          uVar7 = (int)local_4c - (int)pOVar4;
          local_1c = 0;
          local_2c[0] = (OLECHAR *******)((uint)local_2c[0] & 0xffff0000);
          local_8._0_1_ = 5;
          if (pOVar4 != (BSTR)0x0) {
            if (*local_48 == L'\0') {
              uVar5 = 0;
            }
            else {
              uVar5 = _wcslen(local_48);
            }
            FID_conflict_assign(local_2c,(undefined8 *)pOVar1,uVar5);
          }
          local_5c = 0;
          iVar2 = (**(code **)(*param_1 + 0xac))(param_1,&local_5c);
          if (-1 < iVar2) {
            if (local_5c == 0) {
              FUN_4080e983(local_2c,uVar7,(wchar_t)local_54[1]);
            }
            else {
              FUN_4080e9e6(local_2c,0,uVar7,(wchar_t)local_54[1]);
            }
            pppppppOVar6 = (OLECHAR *******)local_2c;
            if (7 < local_18) {
              pppppppOVar6 = local_2c[0];
            }
            FUN_40803e97(&local_48,(OLECHAR *)pppppppOVar6);
          }
          (**(code **)(*param_1 + 100))(param_1,local_48);
          FUN_4080653d(local_2c,'\x01',0);
        }
        goto LAB_4080e707;
      }
    }
  }
  (**(code **)(*param_1 + 100))(param_1,local_48);
LAB_4080e707:
  SysFreeString(local_48);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4082d4c6();
  return;
}


