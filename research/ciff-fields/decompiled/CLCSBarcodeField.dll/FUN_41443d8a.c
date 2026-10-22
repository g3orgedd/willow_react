// Source: CLCSBarcodeField.dll @ 41443d8a; FUN_41443d8a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_41443d8a(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *pvVar1;
  BSTR pOVar2;
  HDC hDC;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  BSTR pOVar6;
  float fVar7;
  HDC pHVar8;
  BSTR pOVar9;
  BSTR pOVar10;
  BSTR pOVar11;
  LONG *pLVar12;
  LONG local_30 [3];
  void *local_24;
  float local_20;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x41443d96;
  uVar4 = 0x80004005;
  if (*(int *)((int)this + 0x44) != 0) {
    local_24 = this;
    (**(code **)(*(int *)*param_3 + 0x80))();
    (**(code **)(*(int *)*param_3 + 0xb0))();
    (**(code **)(*(int *)*param_2 + 0x2c))();
    local_18 = (BSTR)0x0;
    pOVar2 = (BSTR)(5000 / (longlong)(int)local_14);
    dVar5 = DAT_41484280 / (double)local_20;
    local_8 = 0;
    (**(code **)(*(int *)*param_3 + 0x98))();
    pvVar1 = local_24;
    FUN_4144beb9(*(void **)((int)local_24 + 0x44),(IUnknown *)*param_3,(IUnknown *)*param_1,
                 (IUnknown *)*param_2);
    hDC = GetDC((HWND)0x0);
    local_30[0] = 0;
    pOVar6 = (BSTR)local_30;
    local_30[1] = 0;
    fVar7 = 1.4013e-45;
    pHVar8 = hDC;
    pOVar9 = local_14;
    pOVar10 = pOVar2;
    pOVar11 = pOVar6;
    FUN_41402eab(&stack0xffffff88,(int *)&local_18);
    iVar3 = FUN_4144ab5d(*(void **)((int)pvVar1 + 0x44),*(int *)((int)pvVar1 + 0x40),1,local_1c,
                         pOVar6,fVar7,pHVar8,(int)pOVar9,pOVar10,(LONG *)pOVar11);
    local_24 = (void *)((iVar3 * (int)local_14) / (int)dVar5);
    if (local_30[0] < (int)local_24) {
      do {
        pLVar12 = local_30;
        pOVar2 = (BSTR)((int)pOVar2 + 1);
        fVar7 = 1.4013e-45;
        pOVar6 = local_14;
        pHVar8 = hDC;
        pOVar9 = local_14;
        pOVar10 = pOVar2;
        FUN_41402eab(&stack0xffffff88,(int *)&local_18);
        FUN_4144ab5d(*(void **)((int)pvVar1 + 0x44),*(int *)((int)pvVar1 + 0x40),1,local_1c,pOVar6,
                     fVar7,pHVar8,(int)pOVar9,pOVar10,pLVar12);
      } while (local_30[0] < (int)local_24);
    }
    (**(code **)(*(int *)*param_3 + 0xe4))();
    ReleaseDC((HWND)0x0,hDC);
    FUN_4144b05d(*(int *)((int)pvVar1 + 0x44));
    uVar4 = 0;
    SysFreeString(local_18);
  }
  return uVar4;
}


