// Source: CiffHelper.dll @ 4080d800; FUN_4080d800

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4080d800(int *param_1,int *param_2)

{
  double *pdVar1;
  undefined8 *puVar2;
  double local_60;
  double local_58;
  double local_50;
  int local_48;
  wchar_t *local_44;
  int local_40;
  BSTR local_3c;
  BSTR local_38;
  undefined4 local_34;
  uint local_30;
  undefined1 local_2c [8];
  _SYSTEMTIME local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 1;
  local_58 = DAT_4084abe0;
  if (param_2 == (int *)0x0) {
    GetLocalTime(&local_24);
    SystemTimeToVariantTime(&local_24,&local_50);
  }
  else {
    local_48 = 0;
    (**(code **)(*param_2 + 0x24))(param_2,&local_48);
    if (local_48 == 0) {
      (**(code **)(*param_2 + 0xb4))(param_2,&local_34);
      (**(code **)(*param_2 + 0xac))(param_2,&local_30);
      (**(code **)(*param_2 + 0xa4))(param_2,&local_40);
      FUN_40829dc6(&local_24,local_34,local_30,local_40,0,0,0);
      FUN_40805bf7(&local_50);
      pdVar1 = FUN_408294b5(&local_60,&local_50,(int *)&local_24);
      local_50 = *pdVar1;
    }
    else {
      (**(code **)(*param_2 + 0xb4))(param_2,&local_40);
      (**(code **)(*param_2 + 0xac))(param_2,&local_30);
      (**(code **)(*param_2 + 0xa4))(param_2,&local_34);
      FUN_40829d89(&local_50,(WORD)local_40,local_30,(WORD)local_34,0,0,0);
    }
  }
  local_38 = (BSTR)0x0;
  local_8._0_1_ = 2;
  local_58 = local_50;
  (**(code **)(*param_1 + 0x58))(param_1,&local_38);
  local_44 = (wchar_t *)0x0;
  local_8._0_1_ = 3;
  (**(code **)(*param_1 + 0x80))(param_1,&local_44);
  local_3c = (BSTR)0x0;
  local_8._0_1_ = 4;
  puVar2 = (undefined8 *)basic_string<>(local_2c,local_44);
  local_8._0_1_ = 5;
  FUN_4082991d(&local_58,(int *)&local_38,(int *)&local_3c,puVar2,0);
  local_8._0_1_ = 4;
  FUN_4080653d(local_2c,'\x01',0);
  (**(code **)(*param_1 + 100))(param_1,local_3c);
  SysFreeString(local_3c);
  SysFreeString(local_44);
  SysFreeString(local_38);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_4082d4c6();
  return;
}


