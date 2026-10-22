// Source: CLCiffConversion_Data.dll @ 45008b34; FUN_45008b34

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45008b34(void *this,undefined4 *param_1,uint param_2)

{
  int iVar1;
  BSTR local_30;
  LPCWSTR local_2c;
  OLECHAR local_28 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  *param_1 = PTR_DAT_4505101c;
  local_8 = 0;
  if (*(int *)((int)this + 0x18) == 0) {
    FUN_45008a06(param_1,this);
  }
  else {
    local_28[0] = L'\0';
    local_28[1] = L'\0';
    local_28[2] = L'\0';
    local_28[3] = L'\0';
    local_28[4] = L'\0';
    local_28[5] = L'\0';
    local_28[6] = L'\0';
    local_28[7] = L'\0';
    local_28[8] = L'\0';
    local_28[9] = 0;
    FUN_45023625(param_2,local_28,10,10);
    FUN_45001f5d(&local_30,local_28);
    local_2c = (LPCWSTR)0x0;
    local_8 = 2;
    iVar1 = (**(code **)(**(int **)((int)this + 0x18) + 0x2c))
                      (*(int **)((int)this + 0x18),local_30,&local_2c);
    if (iVar1 < 0) {
      FUN_45008a06(param_1,this);
    }
    else {
      FUN_45002365(param_1,local_2c);
    }
    SysFreeString(local_2c);
    SysFreeString(local_30);
  }
  FUN_45022eb8();
  return;
}


