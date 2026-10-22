// Source: CiffMgr.dll @ 6811cb20; FUN_6811cb20

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811cb20(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR pOVar5;
  bool bVar6;
  float10 fVar7;
  _union_2683 local_4c;
  _union_2683 local_3c;
  int local_2c;
  int local_28;
  int local_24;
  wchar_t *local_20;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x3c;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    do {
      param_1 = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2);
      if ((iVar2 != 0) || (param_1 == (int *)0x0)) goto LAB_6811d0d7;
      local_20 = (wchar_t *)0x0;
      iVar2 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (iVar2 < 0) goto switchD_6811cbb4_default;
      iVar3 = FUN_6812e15e(0x6815f828,local_20,0,0xe);
      if (0xd0 < iVar3) {
        if (iVar3 == 0xd2) {
          local_18 = (BSTR)0x0;
          local_8._0_1_ = 8;
          iVar2 = (**(code **)(*param_1 + 0x90))(param_1,PTR_u_AvoidanceDate_6815ff84);
          pOVar5 = local_18;
          if (-1 < iVar2) {
            bVar6 = true;
            if (local_18 == (BSTR)0x0) goto LAB_6811d0bf;
            iVar2 = FUN_68119e5e(piVar1,&local_18);
            pOVar5 = local_18;
          }
          goto LAB_6811d0bd;
        }
        goto switchD_6811cbb4_default;
      }
      if (iVar3 == 0xd0) {
        local_14[0] = (BSTR)0x0;
        local_8._0_1_ = 7;
        iVar2 = (**(code **)(*param_1 + 0x90))(param_1,PTR_u_CalendarRule_6815ff7c);
        pOVar5 = local_14[0];
        if (iVar2 < 0) goto LAB_6811d0bd;
        bVar6 = local_14[0] == (BSTR)0x0;
        if (!bVar6) {
          iVar2 = FUN_6811a0cf(piVar1,local_14);
          pOVar5 = local_14[0];
          goto LAB_6811d0bd;
        }
        goto LAB_6811d0bf;
      }
      switch(iVar3) {
      case 0xb:
        local_1c = (BSTR)0x0;
        local_14[0] = (BSTR)0x0;
        local_24 = 0;
        local_28 = 0;
        FUN_68120b7a((BSTR)&param_1,(BSTR)&local_1c,(BSTR)local_14,&local_24,&local_28);
        (**(code **)(*piVar1 + 0x118))(piVar1);
        (**(code **)(*piVar1 + 0x30))(piVar1,local_14[0]);
        (**(code **)(*piVar1 + 0x38))(piVar1,local_24);
        (**(code **)(*piVar1 + 0x40))(piVar1,local_28);
        goto switchD_6811cbb4_default;
      case 0xc:
        iVar2 = FUN_6812123e(piVar1,(BSTR)&param_1);
        goto switchD_6811cbb4_default;
      case 0xd:
        local_14[0] = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          FUN_6812f862(local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0x80))(piVar1);
          pOVar5 = local_14[0];
        }
        break;
      case 0xe:
        local_14[0] = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          FUN_6812f8d6(local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0x88))(piVar1);
          pOVar5 = local_14[0];
        }
        break;
      case 0xf:
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          FUN_6812f116((ushort *)local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0x90))(piVar1);
          pOVar5 = local_14[0];
        }
        break;
      case 0x10:
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*piVar1 + 0x98))(piVar1);
          pOVar5 = local_14[0];
        }
        break;
      case 0x11:
        local_14[0] = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          FUN_6812f1d4(local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0xa0))(piVar1);
          pOVar5 = local_14[0];
        }
        break;
      case 0x12:
        local_28 = 0;
        local_24 = 0;
        local_1c = (BSTR)0x0;
        local_14[0] = (BSTR)0x0;
        FUN_68120b7a((BSTR)&param_1,(BSTR)&local_28,(BSTR)&local_24,(int *)&local_1c,(int *)local_14
                    );
        (**(code **)(*piVar1 + 0x120))(piVar1);
        (**(code **)(*piVar1 + 0xa8))(piVar1,local_24);
        (**(code **)(*piVar1 + 0xb0))(piVar1,local_1c);
        (**(code **)(*piVar1 + 0xb8))(piVar1,local_14[0]);
        goto switchD_6811cbb4_default;
      case 0x13:
        local_14[0] = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_14[0];
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          fVar7 = (float10)FUN_6812ee95(local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0x48))(piVar1,(double)fVar7);
          pOVar5 = local_14[0];
        }
        break;
      case 0x14:
        local_1c = (BSTR)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
        if ((-1 < iVar2) && (local_1c != (BSTR)0x0)) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*(int *)local_1c + 0x1c))(local_1c,PTR_u_Used_68160040,local_14);
          if ((iVar2 == 0) && (local_14[0] != (BSTR)0x0)) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 3;
            iVar2 = (**(code **)(*(int *)local_14[0] + 0x20))(local_14[0],&local_3c);
            if (local_3c.n2.vt == 8) {
              iVar2 = *piVar1;
              uVar4 = FUN_6812e988((wchar_t *)local_3c._8_4_);
              iVar2 = (**(code **)(iVar2 + 0xd0))(piVar1,uVar4);
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          local_8._0_1_ = 1;
          if (local_14[0] != (BSTR)0x0) {
            (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
          }
          if (iVar2 == 1) {
            iVar2 = 0;
          }
        }
        local_28 = 0;
        local_24 = 0;
        local_14[0] = (BSTR)0x0;
        local_2c = 0;
        FUN_68120b7a((BSTR)&param_1,(BSTR)&local_28,(BSTR)&local_24,(int *)local_14,&local_2c);
        (**(code **)(*piVar1 + 0x128))(piVar1,local_28);
        (**(code **)(*piVar1 + 0xd8))(piVar1,local_24);
        (**(code **)(*piVar1 + 0xe0))(piVar1,local_14[0]);
        (**(code **)(*piVar1 + 0xe8))(piVar1,local_2c);
        pOVar5 = local_1c;
        goto LAB_6811d0bd;
      case 0x15:
        local_1c = (BSTR)0x0;
        local_8._0_1_ = 4;
        iVar2 = (**(code **)(*param_1 + 0x44))(param_1);
        if ((-1 < iVar2) && (local_1c != (BSTR)0x0)) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 5;
          iVar2 = (**(code **)(*(int *)local_1c + 0x1c))(local_1c,PTR_u_Used_68160040,local_14);
          if ((iVar2 == 0) && (local_14[0] != (BSTR)0x0)) {
            FUN_68132710((uint *)&local_4c,0,0x10);
            VariantInit((VARIANTARG *)&local_4c.n2);
            local_8._0_1_ = 6;
            iVar2 = (**(code **)(*(int *)local_14[0] + 0x20))(local_14[0],&local_4c);
            if (local_4c.n2.vt == 8) {
              iVar2 = *piVar1;
              uVar4 = FUN_6812e988((wchar_t *)local_4c._8_4_);
              iVar2 = (**(code **)(iVar2 + 0xf0))(piVar1,uVar4);
            }
            VariantClear((VARIANTARG *)&local_4c.n2);
          }
          local_8._0_1_ = 4;
          if (local_14[0] != (BSTR)0x0) {
            (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
          }
          if (iVar2 == 1) {
            iVar2 = 0;
          }
        }
        local_2c = 0;
        local_28 = 0;
        local_24 = 0;
        local_14[0] = (BSTR)0x0;
        FUN_68120b7a((BSTR)&param_1,(BSTR)&local_2c,(BSTR)&local_28,&local_24,(int *)local_14);
        (**(code **)(*piVar1 + 0x130))(piVar1,local_2c);
        (**(code **)(*piVar1 + 0xf8))(piVar1,local_28);
        (**(code **)(*piVar1 + 0x100))(piVar1,local_24);
        (**(code **)(*piVar1 + 0x108))(piVar1,local_14[0]);
        pOVar5 = local_1c;
LAB_6811d0bd:
        bVar6 = pOVar5 == (BSTR)0x0;
LAB_6811d0bf:
        local_8 = (uint)local_8._1_3_ << 8;
        if (!bVar6) {
          (**(code **)(*(int *)pOVar5 + 8))();
        }
        goto switchD_6811cbb4_default;
      case 0x16:
        local_1c = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_1c;
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*piVar1 + 0xc0))(piVar1);
          pOVar5 = local_1c;
        }
        break;
      case 0x17:
        local_1c = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1);
        pOVar5 = local_1c;
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          FUN_6812e988(local_1c);
          iVar2 = (**(code **)(iVar2 + 200))(piVar1);
          pOVar5 = local_1c;
        }
        break;
      default:
        goto switchD_6811cbb4_default;
      }
      SysFreeString(pOVar5);
switchD_6811cbb4_default:
      SysFreeString(local_20);
LAB_6811d0d7:
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))();
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


