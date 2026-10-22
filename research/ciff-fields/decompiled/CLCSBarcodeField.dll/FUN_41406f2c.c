// Source: CLCSBarcodeField.dll @ 41406f2c; FUN_41406f2c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_41406f2c(undefined4 *param_1)

{
  LPVOID *ppv;
  undefined4 uVar1;
  HRESULT HVar2;
  int iVar3;
  BSTR local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_414a9018;
  param_1[1] = PTR_DAT_414a9018;
  param_1[2] = PTR_DAT_414a9018;
  ppv = (LPVOID *)(param_1 + 3);
  *ppv = (LPVOID)0x0;
  local_8 = 3;
  uStack_7 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar1 = FUN_41407670();
  param_1[4] = uVar1;
  param_1[6] = 0;
  local_8 = 5;
  FUN_4140330b(param_1,L"Missing Translation File");
  FUN_4144ceef();
  FUN_41404baf(param_1 + 1,L"%sLanguages");
  HVar2 = CoCreateInstance((IID *)&DAT_41480ca0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41480dfc,ppv);
  if ((-1 < HVar2) && (*ppv != (LPVOID)0x0)) {
    FUN_41402f15(local_14,(OLECHAR *)param_1[1]);
    _local_8 = CONCAT31(uStack_7,6);
    iVar3 = (**(code **)(*(int *)*ppv + 0x24))(*ppv,local_14[0]);
    if (-1 < iVar3) {
      FUN_414073c6(param_1);
    }
    SysFreeString(local_14[0]);
  }
  return param_1;
}


