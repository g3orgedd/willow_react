// Source: CLCiffConversion_Data.dll @ 45019ea0; FUN_45019ea0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45019ea0(int *param_1)

{
  int *piVar1;
  UINT UVar2;
  HRESULT HVar3;
  int iVar4;
  BSTR local_34;
  BSTR local_30;
  int *local_2c;
  BSTR local_28;
  CLSID local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x45019eac;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    local_28 = (BSTR)0x0;
    local_8 = 0;
    (**(code **)(*piVar1 + 0x78))(piVar1,&local_28);
    UVar2 = SysStringLen(local_28);
    if (UVar2 != 0) {
      local_30 = (BSTR)0x0;
      local_8._0_1_ = 1;
      (**(code **)(*(int *)*param_1 + 0x60))((int *)*param_1,&local_30);
      CLSIDFromProgID(local_28,&local_24);
      local_2c = (int *)0x0;
      HVar3 = CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_450406b4,&local_2c);
      if (HVar3 == 0) {
        local_34 = (BSTR)0x0;
        local_8._0_1_ = 3;
        iVar4 = (**(code **)(*local_2c + 0xc))(local_2c,local_30,&local_34);
        if (iVar4 == 0) {
          (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_34);
        }
        SysFreeString(local_34);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
      SysFreeString(local_30);
    }
    SysFreeString(local_28);
  }
  FUN_45022eb8();
  return;
}


