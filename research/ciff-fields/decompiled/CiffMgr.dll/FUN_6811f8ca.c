// Source: CiffMgr.dll @ 6811f8ca; FUN_6811f8ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811f8ca(void *this,int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  UINT UVar4;
  undefined4 uVar5;
  BSTR bstrString;
  _union_2683 local_4c;
  _union_2683 local_3c;
  void *local_2c;
  BSTR local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_2c = this;
  do {
    bstrString = (BSTR)0x0;
    local_1c = (int *)0x0;
    local_8 = 0;
    iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_1c);
    iVar3 = iVar2;
    if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
      uVar5 = (BSTR)0x0;
      local_28 = (BSTR)0x0;
      local_14[0] = (int *)0x0;
      local_8._0_1_ = 2;
      iVar3 = (**(code **)(*local_1c + 0x44))(local_1c,local_14);
      if (-1 < iVar3) {
        if (local_14[0] != (int *)0x0) {
          local_20 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,3);
          iVar3 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Name_68160030,&local_20);
          if ((iVar3 < 0) || (local_20 == (int *)0x0)) {
            iVar3 = -0x7fffbffb;
            uVar5 = bstrString;
          }
          else {
            iVar3 = (**(code **)(*local_20 + 0x20))(local_20,&local_4c);
            uVar1 = local_4c._8_4_;
            if (((local_4c.n2.vt == 8) && ((BSTR)local_4c._8_4_ != (BSTR)0x0)) &&
               (*(OLECHAR *)local_4c._8_4_ != L'\0')) {
              SysFreeString((BSTR)0x0);
              local_28 = (BSTR)uVar1;
              local_4c.n2.vt = 0;
              uVar5 = uVar1;
            }
            else {
              VariantClear((VARIANTARG *)&local_4c.n2);
            }
          }
          local_8._0_1_ = 2;
          bstrString = (BSTR)uVar5;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
        }
        if (-1 < iVar3) {
          UVar4 = SysStringLen(bstrString);
          if (UVar4 != 0) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 4;
            iVar3 = (**(code **)(*param_1 + 0x28))(param_1,bstrString,&local_3c);
            if ((-1 < iVar3) && (local_3c.n2.vt == 9)) {
              CComQIPtr<>(&local_24,(undefined4 *)local_3c._8_4_);
              if (local_24 == (int *)0x0) {
                iVar3 = -0x7fffbffb;
              }
              else {
                local_18 = (int *)0x0;
                local_8 = CONCAT31(local_8._1_3_,6);
                iVar3 = (**(code **)(*local_1c + 0x90))(local_1c,PTR_u_Param_6815ff04,&local_18);
                if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
                  iVar3 = FUN_6811facb(local_2c,local_24,&local_18);
                }
                local_8._0_1_ = 5;
                if (local_18 != (int *)0x0) {
                  (**(code **)(*local_18 + 8))(local_18);
                }
              }
              local_8._0_1_ = 4;
              if (local_24 != (int *)0x0) {
                (**(code **)(*local_24 + 8))(local_24);
              }
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          if (-1 < iVar3) {
            iVar3 = iVar2;
          }
        }
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      SysFreeString(bstrString);
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  } while (iVar3 == 0);
  if (iVar3 == 1) {
    iVar3 = 0;
  }
  return iVar3;
}


