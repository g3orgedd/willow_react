// Source: CiffMgr.dll @ 6811bf88; FUN_6811bf88

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811bf88(void *this,BSTR param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  BSTR bstrString;
  wchar_t *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0xc;
  if (param_1 == (BSTR)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    do {
      param_1 = (BSTR)0x0;
      local_8 = 0;
      iVar3 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_1);
      if ((iVar3 != 0) || (param_1 == (BSTR)0x0)) goto LAB_6811c212;
      local_1c = (wchar_t *)0x0;
      iVar3 = (**(code **)(*(int *)param_1 + 0x1c))(param_1,&local_1c);
      if (iVar3 < 0) goto switchD_6811c01c_default;
      iVar4 = FUN_6812e15e(0x6815f950,local_1c,0,0xd);
      if (0xab < iVar4) {
        if (iVar4 == 0xac) {
          iVar3 = FUN_6811b6aa(this,(int *)pOVar1,(BSTR)&param_1);
        }
        else if (iVar4 == 0xf2) {
          iVar3 = (**(code **)(*(int *)pOVar1 + 0x2c))(pOVar1,8);
        }
        goto switchD_6811c01c_default;
      }
      if (iVar4 == 0xab) {
        iVar3 = FUN_6812066d(this,(int *)pOVar1,(int *)&param_1);
        goto switchD_6811c01c_default;
      }
      switch(iVar4) {
      case 0x3e:
        local_14[0] = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,local_14);
        bstrString = local_14[0];
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          iVar4 = FUN_6812f116((ushort *)local_14[0]);
          iVar3 = (**(code **)(iVar3 + 0x54))(pOVar1,iVar4);
          bstrString = local_14[0];
        }
        goto LAB_6811c050;
      case 0x3f:
        local_14[0] = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,local_14);
        if (-1 < iVar3) {
          (**(code **)(*(int *)pOVar1 + 0x84))(pOVar1,local_14[0]);
        }
        SysFreeString(local_14[0]);
        local_14[0] = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,1);
        iVar3 = (**(code **)(*(int *)pOVar1 + 0x80))(pOVar1,local_14);
        bstrString = local_14[0];
        if ((-1 < iVar3) &&
           (bVar2 = FUN_68119d18(local_14,L"EN-GB"), bstrString = local_14[0], !bVar2)) {
          *(undefined4 *)((int)this + 4) = 1;
        }
        goto LAB_6811c050;
      case 0x40:
        local_14[0] = (wchar_t *)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,local_14);
        bstrString = local_14[0];
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          uVar5 = FUN_6812e9e2(local_14[0]);
          iVar3 = (**(code **)(iVar3 + 0x90))(pOVar1,uVar5);
          bstrString = local_14[0];
        }
        goto LAB_6811c050;
      case 0x41:
        local_14[0] = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,local_14);
        bstrString = local_14[0];
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*(int *)pOVar1 + 0x7c))(pOVar1,local_14[0]);
          bstrString = local_14[0];
        }
        goto LAB_6811c050;
      case 0x42:
        local_14[0] = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,local_14);
        bstrString = local_14[0];
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          iVar4 = FUN_6812f116((ushort *)local_14[0]);
          iVar3 = (**(code **)(iVar3 + 0x98))(pOVar1,iVar4);
          bstrString = local_14[0];
        }
        goto LAB_6811c050;
      case 0x43:
        local_18 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_18);
        bstrString = local_18;
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*(int *)pOVar1 + 0x5c))(pOVar1,local_18);
          bstrString = local_18;
        }
LAB_6811c050:
        SysFreeString(bstrString);
        break;
      case 0x44:
        (**(code **)(*(int *)pOVar1 + 0xa0))(pOVar1,1);
        iVar3 = FUN_6811e3a4((int *)pOVar1,(BSTR)&param_1);
        break;
      case 0x45:
        iVar3 = FUN_68120fc0((int *)pOVar1,(BSTR)&param_1);
        break;
      case 0x46:
        iVar3 = FUN_68120d2b((int *)pOVar1,(BSTR)&param_1);
        break;
      case 0x47:
        iVar3 = FUN_681234de(pOVar1,(int *)&param_1);
        break;
      case 0x48:
        iVar3 = FUN_6811f7c5((int *)pOVar1,&param_1);
        break;
      case 0x49:
        iVar3 = FUN_6811bb98(pOVar1,&param_1);
      }
switchD_6811c01c_default:
      SysFreeString(local_1c);
LAB_6811c212:
      local_8 = 0xffffffff;
      if (param_1 != (BSTR)0x0) {
        (**(code **)(*(int *)param_1 + 8))(param_1);
      }
    } while (iVar3 == 0);
    if (iVar3 == 1) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


