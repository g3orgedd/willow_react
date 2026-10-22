// Source: CLCiffConversion_Data.dll @ 45019d5f; FUN_45019d5f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45019d5f(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  UINT UVar3;
  HRESULT HVar4;
  undefined4 local_38;
  BSTR local_34;
  BSTR local_30;
  BSTR local_2c;
  int *local_28;
  CLSID local_24;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x6b;
  uStack_7 = 0x45019d;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    local_2c = (BSTR)0x0;
    local_8 = 0;
    uStack_7 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x168))(piVar1,&local_2c);
    if (-1 < iVar2) {
      UVar3 = SysStringLen(local_2c);
      if (UVar3 != 0) {
        HVar4 = CLSIDFromProgID(local_2c,&local_24);
        if (-1 < HVar4) {
          local_28 = (int *)0x0;
          HVar4 = CoCreateInstance(&local_24,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45040834,&local_28);
          if ((-1 < HVar4) && (local_28 != (int *)0x0)) {
            local_30 = (BSTR)0x0;
            local_8 = 2;
            iVar2 = (**(code **)(*(int *)*param_1 + 0x60))((int *)*param_1,&local_30);
            if (-1 < iVar2) {
              local_34 = (BSTR)0x0;
              local_38 = 0;
              local_8 = 3;
              iVar2 = (**(code **)(*(int *)*param_1 + 0x160))((int *)*param_1,&local_38);
              if (-1 < iVar2) {
                iVar2 = (**(code **)(*local_28 + 0xc))(local_28,local_30,local_38,&local_34);
                if ((-1 < iVar2) &&
                   (*(char *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x100 + (int)this) == '\0')) {
                  iVar2 = (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_34);
                  if (-1 < iVar2) {
                    piVar1 = (int *)*param_1;
                    UVar3 = SysStringLen(local_30);
                    (**(code **)(*piVar1 + 0x98))(piVar1,UVar3);
                  }
                }
              }
              SysFreeString(local_34);
            }
            SysFreeString(local_30);
          }
          local_8 = 0;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
      }
    }
    SysFreeString(local_2c);
  }
  FUN_45022eb8();
  return;
}


