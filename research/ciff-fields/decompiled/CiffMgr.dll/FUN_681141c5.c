// Source: CiffMgr.dll @ 681141c5; FUN_681141c5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_681141c5(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x681141d1;
  CComQIPtr<>(&local_18,param_3);
  local_14[0] = (BSTR)0x0;
  local_8 = 1;
  (**(code **)(*local_18 + 0x1c))(local_18,local_14);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)local_14);
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return bVar1;
}


