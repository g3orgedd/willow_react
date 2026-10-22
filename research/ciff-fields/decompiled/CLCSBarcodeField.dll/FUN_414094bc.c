// Source: CLCSBarcodeField.dll @ 414094bc; FUN_414094bc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_414094bc(undefined4 *param_1,BSTR param_2,OLECHAR *param_3)

{
  bool bVar1;
  BSTR pOVar2;
  OLECHAR *pOVar3;
  OLECHAR OVar4;
  bool bVar5;
  UINT UVar6;
  int iVar7;
  int *piVar8;
  undefined1 local_28 [4];
  undefined4 local_24;
  BSTR local_20;
  int *local_1c;
  OLECHAR local_18 [2];
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  pOVar3 = param_3;
  uStack_4 = 0x18;
  local_24 = 0;
  local_8 = 0;
  CComQIPtr<>(&local_1c,*(undefined4 **)param_3);
  local_14[0] = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(*local_1c + 0x168))(local_1c,local_14);
  bVar1 = false;
  if (local_14[0] != (BSTR)0x0) {
    UVar6 = SysStringLen(local_14[0]);
    if (UVar6 != 0) {
      bVar5 = FUN_41403356(local_14,L"Claricom.Modulo10Checksum.1");
      bVar1 = false;
      if (bVar5) {
        bVar1 = true;
      }
    }
  }
  (**(code **)(**(int **)pOVar3 + 0x94))(*(int **)pOVar3,local_28);
  if (!bVar1) {
    UVar6 = SysStringLen(param_2);
    if (UVar6 != 0x11) goto LAB_414095af;
  }
  FUN_41403041(&param_3,param_2);
  local_8 = CONCAT31(local_8._1_3_,3);
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  iVar7 = FUN_41408342((int *)&param_2);
  local_18[0] = (short)iVar7;
  UVar6 = SysStringLen(param_2);
  if (UVar6 == 0x11) {
    FUN_41407cfa(&param_3,local_18);
  }
  else {
    OVar4 = local_18[0];
    FUN_41404888((int *)&param_3);
    param_3[0x11] = OVar4;
  }
  piVar8 = FUN_41402f15(&local_20,param_3);
  FUN_41407c9d(&param_2,piVar8);
  SysFreeString(local_20);
  FUN_414031f1((int *)&param_3);
LAB_414095af:
  pOVar2 = param_2;
  param_2 = (BSTR)0x0;
  *param_1 = pOVar2;
  SysFreeString(local_14[0]);
  local_8 = local_8 & 0xffffff00;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  SysFreeString(param_2);
  return param_1;
}


