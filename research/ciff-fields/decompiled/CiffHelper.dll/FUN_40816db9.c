// Source: CiffHelper.dll @ 40816db9; FUN_40816db9

int FUN_40816db9(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  VARIANTARG local_30;
  BSTR local_20;
  int *local_1c;
  int local_18;
  int local_14;
  BSTR local_10;
  BSTR local_c;
  int *local_8;
  
  CComQIPtr<>(&param_2,(undefined4 *)param_2[2]);
  local_20 = (BSTR)0x0;
  (**(code **)(*param_2 + 0x1c))(param_2,&local_20);
  piVar2 = param_1 + 0x22;
  SysFreeString((BSTR)*piVar2);
  *piVar2 = 0;
  (**(code **)(*param_2 + 0x68))(param_2,piVar2);
  local_8 = (int *)0x0;
  local_c = (BSTR)0x0;
  (**(code **)(*param_2 + 0x5c))(param_2,&local_8);
  local_18 = 0;
  iVar1 = (**(code **)(*local_8 + 0x1c))(local_8,&local_18);
  FUN_4080c114(iVar1);
  local_14 = 0;
  if (0 < local_18) {
    do {
      FUN_40802e76((uint *)&local_30);
      local_14 = local_14 + 1;
      iVar1 = (**(code **)(*local_8 + 0x24))(local_8,local_14,&local_30);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x9c))
                          (param_1,&local_30,param_3,param_4,param_5,param_6,param_7);
        CComQIPtr<>(&local_1c,(undefined4 *)local_30.n1._8_4_);
        if (local_1c != (int *)0x0) {
          local_10 = (BSTR)0x0;
          iVar1 = (**(code **)(*local_1c + 0x60))(local_1c,&local_10);
          FUN_408040a6(&local_c,local_10);
          SysFreeString(local_10);
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
      }
      VariantClear(&local_30);
    } while (local_14 < local_18);
  }
  FUN_408134f7((int *)&param_2,(int *)&local_c);
  (**(code **)(*param_2 + 0x9c))(param_2,local_c);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  SysFreeString(local_c);
  SysFreeString(local_20);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return iVar1;
}


