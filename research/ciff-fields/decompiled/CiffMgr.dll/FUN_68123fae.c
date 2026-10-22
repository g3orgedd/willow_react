// Source: CiffMgr.dll @ 68123fae; FUN_68123fae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68123fae(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  BSTR pOVar3;
  undefined4 bstrString;
  VARIANTARG local_44;
  _union_2683 local_34;
  BSTR local_24;
  int *local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    do {
      local_18 = (int *)0x0;
      local_8 = 0;
      iVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_18);
      if ((iVar1 == 0) && (local_18 != (int *)0x0)) {
        pOVar3 = (BSTR)0x0;
        local_24 = (BSTR)0x0;
        local_20 = (int *)0x0;
        local_8._0_1_ = 2;
        iVar2 = (**(code **)(*local_18 + 0x44))(local_18,&local_20);
        bstrString = (BSTR)0x0;
        if ((-1 < iVar2) && (bstrString = pOVar3, local_20 != (int *)0x0)) {
          local_14[0] = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,3);
          iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_SubIMageRef_6816009c,local_14);
          bstrString = (BSTR)0x0;
          if ((iVar2 == 0) && (bstrString = pOVar3, local_14[0] != (int *)0x0)) {
            (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_34);
            bstrString = local_34._8_4_;
            if ((local_34.n2.vt == 8) &&
               (((BSTR)local_34._8_4_ != (BSTR)0x0 && (*(OLECHAR *)local_34._8_4_ != L'\0')))) {
              SysFreeString((BSTR)0x0);
              local_24 = (BSTR)bstrString;
              local_34.n2.vt = 0;
            }
            else {
              VariantClear((VARIANTARG *)&local_34.n2);
              bstrString = pOVar3;
            }
          }
          local_8._0_1_ = 2;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
        local_1c = (BSTR)0x0;
        local_8._0_1_ = 4;
        iVar2 = (**(code **)(*local_18 + 0x68))(local_18,&local_1c);
        if (iVar2 < 0) {
LAB_681240de:
          iVar1 = iVar2;
        }
        else {
          FUN_68132710((uint *)&local_44,0,0x10);
          VariantInit(&local_44);
          local_8._0_1_ = 5;
          iVar2 = (**(code **)(*param_1 + 0x40))(param_1,bstrString,local_1c,&local_44);
          VariantClear(&local_44);
          if (iVar2 < 0) goto LAB_681240de;
        }
        SysFreeString(local_1c);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
        SysFreeString((BSTR)bstrString);
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    } while (iVar1 == 0);
  }
  return iVar1;
}


