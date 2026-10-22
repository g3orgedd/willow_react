// Source: CLCiffConversion_Data.dll @ 4501c157; FUN_4501c157

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4501c157(void *this,undefined4 *param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined1 local_4c [8];
  int local_44;
  int local_40;
  int *local_3c;
  wchar_t *local_38;
  BSTR local_34;
  BSTR local_30;
  undefined1 local_2c [36];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_34 = (BSTR)0x0;
  local_38 = (wchar_t *)0x0;
  local_30 = (BSTR)0x0;
  local_8 = 2;
  uStack_7 = 0;
  FUN_450040a4(local_4c);
  (**(code **)(*(int *)*param_1 + 0x58))((int *)*param_1,&local_34);
  (**(code **)(*(int *)*param_1 + 0x80))((int *)*param_1,&local_38);
  puVar2 = (undefined8 *)basic_string<>(local_2c,local_38);
  local_8 = 3;
  FUN_4501da6f(local_4c,(int *)&local_34,(int *)&local_30,puVar2,0);
  local_8 = 2;
  FUN_450046d9(local_2c,'\x01',0);
  local_44 = 0;
  piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 100 + (int)this);
  (**(code **)(*piVar1 + 0x90))(piVar1,&local_44);
  if (local_44 == 1) {
    FUN_4500e3e3(param_1,&local_30);
    piVar1 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 100 + (int)this);
    (**(code **)(*piVar1 + 0x94))(piVar1,0);
    *(undefined1 *)((int)this + 8) = 1;
  }
  else {
    local_40 = 0;
    CComQIPtr<>(&local_3c,(undefined4 *)*param_1);
    _local_8 = CONCAT31(uStack_7,4);
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 0x48))(local_3c,&local_40);
    }
    if (local_40 == 5) {
      FUN_4500e3e3(param_1,&local_30);
      (**(code **)(*local_3c + 0x4c))(local_3c,0);
      *(undefined1 *)((int)this + 8) = 1;
    }
    else {
      (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_30);
    }
    local_8 = 2;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
  }
  SysFreeString(local_30);
  SysFreeString(local_38);
  SysFreeString(local_34);
  FUN_45022eb8();
  return;
}


