// Source: CLCiffConversion_Layout.dll @ 4541eaa7; FUN_4541eaa7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT __fastcall FUN_4541eaa7(int param_1)

{
  int *piVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  HVar2 = CoCreateInstance((IID *)&DAT_454473b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454494fc,local_14);
  piVar1 = local_14[0];
  if ((-1 < HVar2) && (local_14[0] != (int *)0x0)) {
    puVar3 = FUN_454028b9(&local_18,*(char **)(param_1 + 8));
    local_8 = CONCAT31(local_8._1_3_,1);
    HVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,*puVar3,param_1 + 4);
    SysFreeString(local_18);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return HVar2;
}


