// Source: CLCiffConversion_Layout.dll @ 4541ae0c; FUN_4541ae0c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_4541ae0c(void *this,BSTR param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  UINT UVar3;
  undefined4 ***pppuVar4;
  int iVar5;
  UINT UVar6;
  BSTR bstrString;
  VARIANTARG local_54;
  BSTR local_44;
  BSTR local_40;
  int *local_3c;
  int *local_38;
  BSTR local_34;
  int *local_30;
  undefined4 **local_2c;
  OLECHAR local_28 [16];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0;
  CComQIPtr<>(&local_30,param_3);
  local_3c = (int *)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*local_30 + 0x5c))(local_30,&local_3c);
  (**(code **)(*local_30 + 0x6c))(local_30,L"FixedText");
  VariantInit(&local_54);
  (**(code **)(*local_3c + 0x28))(local_3c,0,0,1,0,&local_54);
  CComQIPtr<>(&local_38,(undefined4 *)local_54.n1._8_4_);
  local_8._0_1_ = 3;
  VariantClear(&local_54);
  (**(code **)(*local_38 + 0x54))(local_38,0);
  local_34 = (BSTR)0x0;
  local_8._0_1_ = 4;
  bVar1 = FUN_4541e626(this);
  if (bVar1) {
    local_28[0] = L'\0';
    local_28[1] = L'\0';
    local_28[2] = L'\0';
    local_28[3] = L'\0';
    local_28[4] = L'\0';
    local_28[5] = L'\0';
    local_28[6] = L'\0';
    local_28[7] = 0;
    local_28[8] = 0;
    local_28[9] = 0;
    FUN_4542e5e3(0xfbba,local_28,10,10);
    FUN_454028ee(&local_40,local_28);
    local_8._0_1_ = 5;
    piVar2 = FUN_454096a0(&local_44,&local_40);
    FUN_454066f3(&local_34,piVar2);
    SysFreeString(local_44);
    local_8._0_1_ = 4;
    SysFreeString(local_40);
  }
  else {
    FUN_45401cab(&local_34,L"Demonstration Mode");
  }
  bstrString = local_34;
  UVar6 = 0;
  UVar3 = SysStringLen(local_34);
  if (0 < (int)UVar3) {
    basic_string<>(&local_2c,bstrString);
    iVar5 = 0;
    if (0 < (int)UVar3) {
      do {
        pppuVar4 = &local_2c;
        if (7 < CONCAT22(local_28[9],local_28[8])) {
          pppuVar4 = (undefined4 ***)local_2c;
        }
        if (*(short *)((int)pppuVar4 + iVar5 * 2) == 9) {
LAB_4541af52:
          UVar6 = UVar6 + 1;
        }
        else {
          pppuVar4 = &local_2c;
          if (7 < CONCAT22(local_28[9],local_28[8])) {
            pppuVar4 = (undefined4 ***)local_2c;
          }
          if (*(short *)((int)pppuVar4 + iVar5 * 2) == 0x20) goto LAB_4541af52;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)UVar3);
    }
    FUN_4540460c(&local_2c,'\x01',0);
  }
  if (((int)UVar3 < 4) || (UVar3 == UVar6)) {
    FUN_45401cab(&local_34,L"Demonstration Mode");
    bstrString = local_34;
  }
  piVar2 = local_38;
  UVar3 = SysStringLen(bstrString);
  (**(code **)(*piVar2 + 0x98))(piVar2,UVar3);
  (**(code **)(*local_38 + 0x5c))(local_38,bstrString);
  (**(code **)(*local_38 + 100))(local_38,bstrString);
  (**(code **)(*local_30 + 0x9c))(local_30,bstrString);
  (**(code **)(*local_30 + 0xac))(local_30,param_1);
  (**(code **)(*local_30 + 0xb4))(local_30,param_2);
  (**(code **)(*local_30 + 0xbc))(local_30,param_4);
  SysFreeString(bstrString);
  local_8._0_1_ = 2;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  local_8._0_1_ = 1;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  SysFreeString(param_1);
  FUN_4542a957();
  return;
}


