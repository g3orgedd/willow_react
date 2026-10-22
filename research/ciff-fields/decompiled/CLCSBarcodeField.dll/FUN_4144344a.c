// Source: CLCSBarcodeField.dll @ 4144344a; FUN_4144344a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4144344a(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  BSTR pOVar2;
  HDC hdc;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  BSTR extraout_ECX;
  BSTR pOVar6;
  double dVar7;
  BSTR pOVar8;
  HDC pHVar9;
  undefined4 **ppuVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *local_38;
  int local_34;
  BSTR local_30;
  float local_2c;
  float local_28;
  int local_24;
  int local_20;
  BSTR local_1c;
  int local_18;
  int local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x41443456;
  local_24 = 1;
  (**(code **)(*(int *)*param_2 + 0x54))();
  puVar4 = param_4;
  local_1c = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(*(int *)*param_4 + 0x98))();
  local_14 = 0;
  (**(code **)(*(int *)*puVar4 + 0xc0))();
  piVar11 = param_3;
  (**(code **)(*(int *)*param_3 + 0x2c))();
  (**(code **)(*(int *)*piVar11 + 0x34))();
  (**(code **)(*(int *)*puVar4 + 0xb0))();
  dVar7 = (double)local_20 * DAT_414825d0;
  iVar1 = FUN_41409304(((double)local_28 * dVar7) / DAT_41483fb8);
  pOVar2 = (BSTR)FUN_41409304(((double)local_2c * dVar7) / DAT_41483fb8);
  (**(code **)(*(int *)*puVar4 + 0xe0))();
  hdc = CreateCompatibleDC((HDC)0x0);
  local_38 = (undefined4 *)0x0;
  local_34 = 0;
  FUN_4144beb9(*(void **)(local_18 + 0x44),(IUnknown *)*param_4,(IUnknown *)*param_2,
               (IUnknown *)*param_3);
  ppuVar10 = &local_38;
  fVar3 = (float)(uint)(local_14 == 1);
  pOVar8 = extraout_ECX;
  pHVar9 = hdc;
  iVar5 = local_20;
  FUN_41402eab(&stack0xffffff60,(int *)&local_1c);
  param_2 = (undefined4 *)
            FUN_4144ab5d(*(void **)(local_18 + 0x44),*(int *)(local_18 + 0x40),iVar1,pOVar2,pOVar8,
                         fVar3,pHVar9,iVar5,local_30,(LONG *)ppuVar10);
  pOVar6 = (BSTR)(uint)(local_14 == 1);
  pOVar8 = pOVar6;
  FUN_41402eab(&stack0xffffff6c,(int *)&local_1c);
  iVar5 = local_18;
  iVar1 = FUN_4144aa18(*(void **)(local_18 + 0x44),*(int **)(local_18 + 0x40),iVar1,(int)pOVar2,
                       pOVar8,(char)pOVar6);
  FUN_4144b05d(*(int *)(iVar5 + 0x44));
  DeleteDC(hdc);
  puVar4 = param_2;
  if (local_14 != 0) {
    iVar1 = iVar1 + local_34;
    if ((int)param_2 < (int)local_38) {
      puVar4 = local_38;
    }
  }
  *param_1 = (int)puVar4;
  param_1[1] = iVar1;
  if (local_24 == 0) {
    FUN_4144c328(&param_2);
    piVar12 = param_3;
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar11 = (int *)*param_3;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))();
    }
    iVar5 = FUN_4144c3fb((int)*(double *)(local_18 + 0x30),1.4013e-45,piVar11);
    *param_1 = iVar5;
    piVar11 = (int *)*piVar12;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))();
    }
    iVar5 = FUN_4144c36e(*param_1,1.4013e-45,piVar11);
    *param_1 = iVar5;
    piVar12 = (int *)*piVar12;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    fVar3 = 1.4013e-45;
    iVar5 = FUN_41409304(((double)*param_1 * (double)local_20) / DAT_41481000);
    iVar5 = FUN_4144c3fb(iVar5,fVar3,piVar12);
    *param_1 = iVar5;
    local_8 = local_8 & 0xffffff00;
    FUN_4144c348(&param_2);
  }
  SysFreeString(local_1c);
  return 0;
}


