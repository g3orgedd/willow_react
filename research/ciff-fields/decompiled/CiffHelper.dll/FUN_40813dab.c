// Source: CiffHelper.dll @ 40813dab; FUN_40813dab

void FUN_40813dab(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5,undefined4 param_6,ULONG param_7,int *param_8,undefined4 param_9
                 ,VARIANTARG *param_10)

{
  char cVar1;
  _union_2683 local_40;
  undefined4 local_30;
  int *local_2c;
  wchar_t *local_28;
  int *local_24;
  wchar_t local_20 [12];
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  local_30 = param_1;
  local_40._0_4_ = param_6;
  local_40.decVal.Hi32 = param_7;
  local_40._8_4_ = param_8;
  local_40._12_4_ = param_9;
  if (param_10 != (VARIANTARG *)0x0) {
    if (param_8 != (int *)0x0) {
      (**(code **)(*param_8 + 4))(param_8);
    }
    local_24 = param_4;
    if (param_4 != (int *)0x0) {
      (**(code **)(*param_4 + 4))(param_4);
    }
    if ((param_8 != (int *)0x0) && (local_24 != (int *)0x0)) {
      local_28 = (wchar_t *)0x0;
      (**(code **)(*param_8 + 0x1c))(param_8,&local_28);
      basic_string<>(local_20,local_28);
      local_2c = (int *)0x0;
      cVar1 = FUN_4081d219(&local_24,&local_2c,local_20);
      if (cVar1 != '\0') {
        FUN_40802e76((uint *)&local_40);
        FUN_4081214f(&local_40,param_8);
        FUN_4080801f(&local_40,param_10);
        VariantClear((VARIANTARG *)&local_40.n2);
      }
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      FUN_4080653d(local_20,'\x01',0);
      SysFreeString(local_28);
    }
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    if (param_8 != (int *)0x0) {
      (**(code **)(*param_8 + 8))(param_8);
    }
  }
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


