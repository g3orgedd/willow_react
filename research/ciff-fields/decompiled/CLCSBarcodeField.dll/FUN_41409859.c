// Source: CLCSBarcodeField.dll @ 41409859; FUN_41409859

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_41409859(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,LPSIZE param_4)

{
  undefined4 *puVar1;
  int iVar2;
  HDC hdc;
  UINT c;
  double dVar3;
  BYTE local_2c [4];
  int local_28;
  int local_24;
  void *local_20;
  int local_1c;
  BSTR local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 0x1c;
  local_8 = 0x41409865;
  local_1c = 1;
  param_4->cx = 0;
  param_4->cy = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0xc0))((int *)*param_1,&local_1c);
  if (-1 < iVar2) {
    if (local_1c == 0) {
      iVar2 = 0;
    }
    else {
      local_18 = (BSTR)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*puVar1 + 0xd0))((int *)*puVar1,&local_18);
      if ((((-1 < iVar2) &&
           (iVar2 = (**(code **)(*(int *)*puVar1 + 0xd8))((int *)*puVar1,local_2c), -1 < iVar2)) &&
          (iVar2 = (**(code **)(*(int *)*puVar1 + 0xe8))((int *)*puVar1,&local_28), -1 < iVar2)) &&
         (((iVar2 = (**(code **)(*(int *)*puVar1 + 0xe0))((int *)*puVar1,&param_1), -1 < iVar2 &&
           (iVar2 = (**(code **)(*(int *)*puVar1 + 0xb0))((int *)*puVar1,&local_24),
           puVar1 = param_2, -1 < iVar2)) &&
          (iVar2 = (**(code **)(*(int *)*param_2 + 0x2c))((int *)*param_2,local_14), -1 < iVar2))))
      {
        param_2 = (undefined4 *)(int)((double)(local_14[0] * _DAT_41481060) + _DAT_41481058);
        iVar2 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,local_14);
        if (-1 < iVar2) {
          dVar3 = (double)(local_14[0] * _DAT_41481060) + _DAT_41481058;
          if (local_24 < 1000) {
            param_1 = (undefined4 *)((local_24 * (int)param_1) / 1000);
          }
          if ((int)param_1 < 3) {
            param_1 = (undefined4 *)0x3;
          }
          hdc = GetDC((HWND)0x0);
          iVar2 = FUN_41409b1b(local_20,hdc,&local_18,local_2c[0],local_28,(int)param_1,(int)param_2
                               ,(int)dVar3);
          puVar1 = param_3;
          if (-1 < iVar2) {
            c = SysStringLen((BSTR)*param_3);
            GetTextExtentPoint32W(hdc,(LPCWSTR)*puVar1,c,param_4);
            FUN_41409aec(local_20,hdc);
          }
          ReleaseDC((HWND)0x0,hdc);
          iVar2 = 0;
        }
      }
      SysFreeString(local_18);
    }
  }
  return iVar2;
}


