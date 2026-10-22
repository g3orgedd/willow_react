// Source: CiffMgr.dll @ 6811d9a6; FUN_6811d9a6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_6811d9a6(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  DWORD DVar7;
  uint extraout_EAX;
  wchar_t *pwVar8;
  DWORD DVar9;
  code *pcVar10;
  bool bVar11;
  int local_34;
  wchar_t *local_30;
  wchar_t *local_2c;
  wchar_t *local_28;
  int *local_24;
  wchar_t *local_20;
  wchar_t *local_1c;
  wchar_t *local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x28;
  local_8 = 0x6811d9b2;
  pcVar10 = SysFreeString_exref;
  local_14 = this;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    do {
      DVar3 = GetTickCount();
      local_34 = 0;
      param_1 = (int *)0x0;
      local_8 = 0;
      uVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_1);
      if ((uVar2 != 0) || (param_1 == (int *)0x0)) goto LAB_6811df81;
      local_30 = (wchar_t *)0x0;
      uVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_30);
      if ((int)uVar2 < 0) goto switchD_6811da4a_default;
      iVar4 = FUN_6812e15e(0x6815f8a0,local_30,0,0x15);
      if (0x5f < iVar4) {
        if (iVar4 == 0xe6) {
          CComQIPtr<>(&local_2c,piVar1);
          local_8._0_1_ = 1;
          bVar11 = true;
          pwVar8 = local_2c;
          if (local_2c == (wchar_t *)0x0) goto LAB_6811df70;
          local_20 = (wchar_t *)0x0;
          uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
          if (-1 < (int)uVar2) {
            uVar2 = (**(code **)(*(int *)local_2c + 0x20))(local_2c,local_20);
          }
          (*pcVar10)(local_20);
          pwVar8 = local_2c;
          goto LAB_6811df6e;
        }
        goto switchD_6811da4a_default;
      }
      if (iVar4 == 0x5f) {
        local_20 = (wchar_t *)0x0;
        local_8._0_1_ = 5;
        uVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,&local_20);
        pwVar8 = local_20;
        if (-1 < (int)uVar2) {
          bVar11 = true;
          if (local_20 == (wchar_t *)0x0) goto LAB_6811df70;
          local_18 = (wchar_t *)0x0;
          local_8 = CONCAT31(local_8._1_3_,6);
          uVar2 = (**(code **)(*param_1 + 0x90))(param_1,PTR_u_Rect_6815fdb8,&local_18);
          if ((-1 < (int)uVar2) && (local_18 != (wchar_t *)0x0)) {
            uVar2 = FUN_6811b867(local_14,&local_20,&local_18);
          }
          local_8._0_1_ = 5;
          pwVar8 = local_20;
          if (local_18 != (wchar_t *)0x0) {
            (**(code **)(*(int *)local_18 + 8))(local_18);
            pwVar8 = local_20;
          }
        }
        goto LAB_6811df6e;
      }
      switch(iVar4) {
      case 0x29:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          uVar2 = (**(code **)(*piVar1 + 0x6c))(piVar1,local_20);
        }
        break;
      case 0x2a:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          uVar2 = (**(code **)(*piVar1 + 0x74))(piVar1,local_20);
        }
        break;
      case 0x2b:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          uVar5 = FUN_6812e988(local_20);
          uVar2 = (**(code **)(iVar4 + 0x28))(piVar1,uVar5);
        }
        break;
      case 0x2c:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x30))(piVar1,iVar6);
        }
        break;
      case 0x2d:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x38))(piVar1,iVar6);
        }
        break;
      case 0x2e:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x7c))(piVar1,iVar6);
        }
        break;
      case 0x2f:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x84))(piVar1,iVar6);
        }
        break;
      case 0x30:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x8c))(piVar1,iVar6);
        }
        break;
      case 0x31:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          iVar6 = FUN_6812f116((ushort *)local_20);
          uVar2 = (**(code **)(iVar4 + 0x40))(piVar1,iVar6);
        }
        break;
      case 0x32:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          uVar5 = FUN_6812e988(local_20);
          uVar2 = (**(code **)(iVar4 + 0x94))(piVar1,uVar5);
        }
        break;
      case 0x33:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          uVar5 = FUN_6812e988(local_20);
          uVar2 = (**(code **)(iVar4 + 0x48))(piVar1,uVar5);
        }
        break;
      case 0x34:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          uVar5 = FUN_6812e988(local_20);
          uVar2 = (**(code **)(iVar4 + 0x50))(piVar1,uVar5);
        }
        break;
      case 0x35:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          iVar4 = *piVar1;
          uVar5 = FUN_6812f776(local_20);
          uVar2 = (**(code **)(iVar4 + 0x58))(piVar1,uVar5);
        }
        break;
      case 0x36:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          uVar2 = (**(code **)(*piVar1 + 0x9c))(piVar1,local_20);
        }
        break;
      case 0x37:
        local_20 = (wchar_t *)0x0;
        uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
        if (-1 < (int)uVar2) {
          uVar2 = (**(code **)(*piVar1 + 0xa4))(piVar1,local_20);
        }
        break;
      case 0x38:
        CComQIPtr<>(&local_28,piVar1);
        local_8._0_1_ = 2;
        bVar11 = local_28 == (wchar_t *)0x0;
        pwVar8 = local_28;
        if (!bVar11) {
          local_20 = (wchar_t *)0x0;
          uVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_20);
          pwVar8 = local_28;
          if (-1 < (int)uVar2) {
            iVar4 = *(int *)local_28;
            uVar5 = FUN_6812f2c7(local_20);
            uVar2 = (**(code **)(iVar4 + 0x10))(pwVar8,uVar5);
            pcVar10 = SysFreeString_exref;
          }
          (*pcVar10)(local_20);
          pwVar8 = local_28;
          goto LAB_6811df6e;
        }
        goto LAB_6811df70;
      case 0x39:
        DVar9 = GetTickCount();
        local_24 = (int *)0x0;
        local_8._0_1_ = 3;
        uVar2 = (**(code **)(*piVar1 + 0x5c))(piVar1,&local_24);
        if ((-1 < (int)uVar2) && (local_24 != (int *)0x0)) {
          local_18 = (wchar_t *)0x0;
          local_8 = CONCAT31(local_8._1_3_,4);
          uVar2 = (**(code **)(*param_1 + 0x90))(param_1,PTR_u_Object_6815fd2c,&local_18);
          if ((-1 < (int)uVar2) && (local_18 != (wchar_t *)0x0)) {
            uVar2 = FUN_6811c26c(local_14,&local_24,&local_18);
          }
          local_8._0_1_ = 3;
          if (local_18 != (wchar_t *)0x0) {
            (**(code **)(*(int *)local_18 + 8))(local_18);
          }
        }
        DVar7 = GetTickCount();
        local_8 = (uint)local_8._1_3_ << 8;
        local_34 = DVar7 - DVar9;
        *(int *)((int)local_14 + 0xb48) = *(int *)((int)local_14 + 0xb48) + local_34;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))(local_24);
        }
        goto switchD_6811da4a_default;
      case 0x3a:
        local_18 = (wchar_t *)0x0;
        local_8._0_1_ = 7;
        uVar2 = (**(code **)(*param_1 + 0x30))(param_1,&local_18);
        pwVar8 = local_18;
        if (uVar2 == 0) {
          bVar11 = true;
          if (local_18 == (wchar_t *)0x0) goto LAB_6811df70;
          uVar2 = FUN_6812282a(piVar1,&local_18);
          pwVar8 = local_18;
        }
        goto LAB_6811df6e;
      case 0x3b:
        local_1c = (wchar_t *)0x0;
        local_8._0_1_ = 8;
        uVar2 = (**(code **)(*param_1 + 0x30))(param_1,&local_1c);
        pwVar8 = local_1c;
        if (uVar2 == 0) {
          bVar11 = true;
          if (local_1c == (wchar_t *)0x0) goto LAB_6811df70;
          uVar2 = FUN_6811a3ca(piVar1,&local_1c);
          pwVar8 = local_1c;
        }
LAB_6811df6e:
        bVar11 = pwVar8 == (wchar_t *)0x0;
LAB_6811df70:
        local_8 = (uint)local_8._1_3_ << 8;
        if (!bVar11) {
          (**(code **)(*(int *)pwVar8 + 8))(pwVar8);
        }
        goto switchD_6811da4a_default;
      case 0x3c:
        FUN_6811e7a1(piVar1,(int *)&param_1);
        uVar2 = extraout_EAX;
      default:
        goto switchD_6811da4a_default;
      }
      (*pcVar10)(local_20);
switchD_6811da4a_default:
      (*pcVar10)(local_30);
LAB_6811df81:
      DVar9 = GetTickCount();
      local_8 = 0xffffffff;
      *(int *)((int)local_14 + 0xb44) =
           *(int *)((int)local_14 + 0xb44) + ((DVar9 - local_34) - DVar3);
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    } while (uVar2 == 0);
    if (uVar2 == 1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


