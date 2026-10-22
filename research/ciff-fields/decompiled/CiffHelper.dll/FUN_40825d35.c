// Source: CiffHelper.dll @ 40825d35; FUN_40825d35

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_40825d35(BSTR param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  bool bVar2;
  UINT UVar3;
  int iVar4;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  iVar4 = 0;
  local_8 = 0;
  bVar2 = FUN_40803ed6(&param_1,L"Pegasus (Basic Driver)");
  if (!bVar2) {
    bVar2 = FUN_40803ed6(&param_1,L"Pegasus (Full Driver)");
    if (!bVar2) {
      bVar2 = FUN_40803ed6(&param_1,L"VJ6210 (Basic Driver)");
      if (!bVar2) {
        bVar2 = FUN_40803ed6(&param_1,L"VJ6210 (Full Driver)");
        if (!bVar2) {
          bVar2 = FUN_40803ed6(&param_1,L"TT3 (Basic Driver)");
          if (!bVar2) {
            bVar2 = FUN_40803ed6(&param_1,L"TT3 (Full Driver)");
            if (!bVar2) goto LAB_40825dfe;
          }
        }
      }
    }
  }
  puVar1 = param_2;
  local_14[0] = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = (**(code **)(*(int *)*param_2 + 0x4c))((int *)*param_2,local_14);
  if (-1 < iVar4) {
    UVar3 = SysStringLen(local_14[0]);
    if (UVar3 != 0) {
      bVar2 = FUN_40803ed6(local_14,L"Default");
      if (bVar2) {
        iVar4 = (**(code **)(*(int *)*puVar1 + 0x50))((int *)*puVar1,L"Continuous");
      }
    }
  }
  SysFreeString(local_14[0]);
LAB_40825dfe:
  SysFreeString(param_1);
  return iVar4;
}


