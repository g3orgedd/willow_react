// Source: CLARiSOFT.exe @ 00e056b2; FUN_00e056b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall FUN_00e056b2(int param_1,undefined4 *param_2,BSTR param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    iVar4 = 0;
    puVar5 = (undefined4 *)**(undefined4 **)(param_1 + 4);
    if (0 < iVar1) {
      do {
        iVar2 = puVar5[2];
        bVar3 = ATL::CComBSTR::operator==((CComBSTR *)(iVar2 + 4),(CComBSTR *)&param_3);
        if (bVar3) {
          FUN_00e03ab8(param_2,(int *)(iVar2 + 8));
          SysFreeString(param_3);
          return param_2;
        }
        puVar5 = (undefined4 *)*puVar5;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  *param_2 = 0;
  SysFreeString(param_3);
  return param_2;
}


