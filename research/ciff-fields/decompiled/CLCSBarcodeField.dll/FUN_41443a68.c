// Source: CLCSBarcodeField.dll @ 41443a68; FUN_41443a68

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x41443c80) */
/* WARNING: Removing unreachable block (ram,0x41443c93) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_41443a68(void *this,int *param_1,undefined4 *param_2,int *param_3,BSTR param_4)

{
  bool bVar1;
  BSTR pOVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  BSTR extraout_ECX;
  double dVar8;
  double dVar9;
  BSTR pOVar10;
  HDC pHVar11;
  BSTR pOVar12;
  LONG *pLVar13;
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
  BSTR local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_4;
  uStack_4 = 100;
  local_8 = 0x41443a74;
  uVar4 = 0x80004005;
  if (*(int *)((int)this + 0x44) != 0) {
    iVar5 = param_1[2];
    local_18 = (BSTR)(param_1[3] - param_1[1]);
    iVar6 = *param_1;
    (**(code **)(**(int **)param_4 + 0xb0))();
    (**(code **)(**(int **)pOVar2 + 0x84))();
    local_4c = (double)(iVar5 - iVar6);
    (**(code **)(*(int *)*param_3 + 0x2c))();
    iVar5 = FUN_414092db(local_24 * _DAT_4148100c);
    local_3c = (double)iVar5 / _DAT_41482570;
    (**(code **)(*(int *)*param_2 + 0x54))();
    if (local_20 == 1) {
      local_4c = local_4c / local_3c;
    }
    dVar9 = (local_4c * DAT_41481000) / *(double *)((int)this + 0x30);
    if (_DAT_41484290 < dVar9) {
      iVar5 = (**(code **)(*(int *)this + 0x28))();
      dVar9 = (double)iVar5;
    }
    iVar5 = FUN_41409304((local_3c * _DAT_41482570 *
                         ((*(double *)((int)this + 0x28) * dVar9) / DAT_41481000)) / _DAT_41482570);
    pOVar2 = param_4;
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    local_14 = iVar5;
    (**(code **)(**(int **)param_4 + 0xc0))();
    (**(code **)(**(int **)pOVar2 + 0xe0))();
    dVar9 = *(double *)((int)this + 0x28) * local_3c;
    local_64 = 0.0;
    FUN_4144beb9(*(void **)((int)this + 0x44),*(IUnknown **)pOVar2,(IUnknown *)*param_2,
                 (IUnknown *)*param_3);
    do {
      local_1c = GetDC((HWND)0x0);
      param_4 = (BSTR)0x0;
      local_8 = 0;
      (**(code **)(**(int **)pOVar2 + 0x98))();
      pLVar13 = local_54;
      local_54[0] = 0;
      local_54[1] = 0;
      dVar8 = ((double)iVar5 * DAT_41481000) / dVar9;
      iVar6 = (int)dVar8;
      fVar7 = 0.0;
      pOVar10 = extraout_ECX;
      pHVar11 = local_1c;
      pOVar12 = local_28;
      FUN_41402eab(&stack0xffffff34,(int *)&param_4);
      iVar6 = FUN_4144ab5d(*(void **)((int)this + 0x44),*(int *)((int)this + 0x40),iVar5,local_18,
                           pOVar10,fVar7,pHVar11,iVar6,pOVar12,pLVar13);
      local_34 = (double)iVar6 / local_3c;
      dVar3 = local_34;
      if (local_34 <= local_4c) {
        if ((local_4c <= local_34) ||
           (iVar6 = (**(code **)(*(int *)this + 0x28))(), dVar3 = local_34, (double)iVar6 <= dVar8))
        goto LAB_41443d17;
        local_14 = iVar5 + 1;
        local_64 = local_34;
        bVar1 = true;
      }
      else {
        if (_DAT_41484278 < local_64) {
          local_44 = local_64;
          dVar3 = local_44;
        }
        else if (1 < iVar5) {
          local_14 = iVar5 + -1;
          bVar1 = true;
          goto LAB_41443d19;
        }
LAB_41443d17:
        local_44 = dVar3;
        bVar1 = false;
      }
LAB_41443d19:
      ReleaseDC((HWND)0x0,local_1c);
      local_8 = 0xffffffff;
      SysFreeString(param_4);
      iVar5 = local_14;
    } while (bVar1);
    FUN_4144b05d(*(int *)((int)this + 0x44));
    (**(code **)(**(int **)pOVar2 + 0x7c))();
    (**(code **)(**(int **)pOVar2 + 0xb4))();
    FUN_41443ef9(this,param_2,param_3,(undefined4 *)pOVar2);
    uVar4 = 0;
  }
  return uVar4;
}


