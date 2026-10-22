// Source: CiffHelper.dll @ 4080d4a9; FUN_4080d4a9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4080d4a9(int *param_1,int param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  undefined1 local_48 [8];
  int local_40;
  BSTR local_3c;
  BSTR local_38;
  BSTR local_34;
  wchar_t *local_30;
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  FUN_40805bf7(local_48);
  local_30 = (wchar_t *)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x80))(param_1,&local_30);
  (**(code **)(*param_1 + 0x28))(param_1,&local_40);
  local_3c = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_40 == 4) {
    (**(code **)(*param_1 + 0xb4))(param_1);
  }
  bVar1 = FUN_40803ed6(&local_3c,L"SinceJobSelection");
  if (bVar1) {
    FUN_408293aa(local_48,0);
  }
  local_38 = (BSTR)0x0;
  local_8._0_1_ = 3;
  (**(code **)(*param_1 + 0x58))(param_1,&local_38);
  local_34 = (BSTR)0x0;
  local_8._0_1_ = 4;
  puVar2 = (undefined8 *)basic_string<>(local_2c,local_30);
  local_8._0_1_ = 5;
  FUN_4082991d(local_48,(int *)&local_38,(int *)&local_34,puVar2,param_2);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_4080653d(local_2c,'\x01',0);
  (**(code **)(*param_1 + 100))(param_1,local_34);
  SysFreeString(local_34);
  SysFreeString(local_38);
  SysFreeString(local_3c);
  SysFreeString(local_30);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4082d4c6();
  return;
}


