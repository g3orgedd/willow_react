// Source: CLCSSmallBarcode.dll @ 4205ea7f; FUN_4205ea7f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x4205ec66) */
/* WARNING: Removing unreachable block (ram,0x4205ec79) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_4205ea7f(void *this,int *param_1,BSTR param_2,int *param_3,BSTR param_4)

{
  bool bVar1;
  BSTR pOVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  float fVar6;
  BSTR extraout_ECX;
  int iVar7;
  float10 fVar8;
  double dVar9;
  double dVar10;
  BSTR pOVar11;
  HDC pHVar12;
  BSTR pOVar13;
  LONG *pLVar14;
  double local_64;
  LONG local_54 [2];
  double local_4c;
  double local_44;
  double local_3c;
  double local_34;
  BSTR local_28;
  float local_24;
  int local_20;
  HDC local_1c;
  int local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_4;
  uStack_4 = 0x6c;
  local_8 = 0x4205ea8b;
  uVar4 = 0x80004005;
  if (*(int *)((int)this + 0x40) != 0) {
    iVar7 = param_1[2];
    local_18 = param_1[3] - param_1[1];
    iVar5 = *param_1;
    (**(code **)(**(int **)param_4 + 0xb0))();
    (**(code **)(**(int **)pOVar2 + 0x84))();
    local_4c = (double)(iVar7 - iVar5);
    (**(code **)(*(int *)*param_3 + 0x2c))();
    local_3c = (double)local_24;
    (**(code **)(**(int **)param_2 + 0x54))();
    if (local_20 == 1) {
      local_4c = local_4c / local_3c;
    }
    dVar9 = (local_4c * DAT_42089818) / *(double *)((int)this + 0x30);
    if (_DAT_4209e1b0 < dVar9) {
      fVar8 = FUN_42066adf((int)this,param_3);
      dVar9 = (double)fVar8;
    }
    pOVar2 = param_4;
    iVar7 = (int)((local_3c * DAT_42089810 *
                  ((*(double *)((int)this + 0x28) * dVar9) / DAT_42089818)) / DAT_42089810);
    if (iVar7 < 1) {
      iVar7 = 1;
    }
    local_14 = iVar7;
    (**(code **)(**(int **)param_4 + 0xc0))();
    (**(code **)(**(int **)pOVar2 + 0xe0))();
    dVar9 = *(double *)((int)this + 0x28) * local_3c;
    local_64 = 0.0;
    FUN_4202bc38(*(void **)((int)this + 0x40),*(IUnknown **)pOVar2,*(IUnknown **)param_2,
                 (IUnknown *)*param_3);
    do {
      local_1c = GetDC((HWND)0x0);
      param_4 = (BSTR)0x0;
      local_8 = 0;
      (**(code **)(**(int **)pOVar2 + 0x98))();
      pLVar14 = local_54;
      local_54[0] = 0;
      local_54[1] = 0;
      dVar10 = ((double)iVar7 * DAT_42089818) / dVar9;
      iVar5 = (int)dVar10;
      fVar6 = 0.0;
      pOVar11 = extraout_ECX;
      pHVar12 = local_1c;
      pOVar13 = local_28;
      FUN_42002e4a(&stack0xffffff2c,(int *)&param_4);
      iVar5 = FUN_4202aa79(*(void **)((int)this + 0x40),*(int *)((int)this + 0x14),iVar7,local_18,
                           pOVar11,fVar6,pHVar12,iVar5,pOVar13,pLVar14);
      local_34 = (double)iVar5 / local_3c;
      dVar3 = local_34;
      if (local_34 <= local_4c) {
        if ((local_4c <= local_34) ||
           (fVar8 = FUN_42066adf((int)this,param_3), dVar3 = local_34, (double)fVar8 <= dVar10))
        goto LAB_4205ecf6;
        local_14 = iVar7 + 1;
        local_64 = local_34;
LAB_4205ecea:
        bVar1 = true;
      }
      else {
        if (local_64 <= _DAT_420923d0) {
          if (1 < iVar7) {
            local_14 = iVar7 + -1;
            goto LAB_4205ecea;
          }
        }
        else {
          local_44 = local_64;
          dVar3 = local_44;
        }
LAB_4205ecf6:
        local_44 = dVar3;
        bVar1 = false;
      }
      ReleaseDC((HWND)0x0,local_1c);
      local_8 = 0xffffffff;
      SysFreeString(param_4);
      iVar7 = local_14;
    } while (bVar1);
    FUN_4202aea0(*(int *)((int)this + 0x40));
    (**(code **)(**(int **)pOVar2 + 0x7c))();
    (**(code **)(**(int **)pOVar2 + 0xb4))();
    FUN_4205ed69(this,param_2,param_3,(int *)pOVar2);
    uVar4 = 0;
  }
  return uVar4;
}


