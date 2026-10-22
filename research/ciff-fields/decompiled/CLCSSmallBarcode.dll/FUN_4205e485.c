// Source: CLCSSmallBarcode.dll @ 4205e485; FUN_4205e485

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4205e485(int *param_1,BSTR param_2,int *param_3,int *param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  HDC hdc;
  float fVar4;
  int iVar5;
  LONG LVar6;
  BSTR extraout_ECX;
  BSTR pOVar7;
  BSTR pOVar8;
  HDC pHVar9;
  int *piVar10;
  LONG *pLVar11;
  int *piVar12;
  LONG local_44 [3];
  BSTR local_38;
  float local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  BSTR local_20;
  int local_1c;
  int local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4205e491;
  FUN_42002e41(local_44 + 2);
  local_8 = 0;
  piVar12 = param_1 + 1;
  (**(code **)(*(int *)*param_4 + 0xb8))();
  if (*piVar12 == 0) {
    *piVar12 = 1;
  }
  local_24 = 1;
  (**(code **)(**(int **)param_2 + 0x54))();
  local_20 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*(int *)*param_4 + 0x98))();
  local_18 = 0;
  (**(code **)(*(int *)*param_4 + 0xc0))();
  (**(code **)(*(int *)*param_3 + 0x2c))();
  (**(code **)(*(int *)*param_3 + 0x34))();
  (**(code **)(*(int *)*param_4 + 0xb0))();
  iVar2 = FUN_42004376(((double)local_1c * _DAT_42089800 * (double)local_30) / DAT_42092e78);
  iVar3 = FUN_4200434d((float)*piVar12 * local_34);
  (**(code **)(*(int *)*param_4 + 0xe0))();
  hdc = CreateCompatibleDC((HDC)0x0);
  local_44[0] = 0;
  local_44[1] = 0;
  FUN_4202bc38(*(void **)((int)local_14 + 0x40),(IUnknown *)*param_4,*(IUnknown **)param_2,
               (IUnknown *)*param_3);
  pLVar11 = local_44;
  fVar4 = (float)(uint)(local_18 == 1);
  pOVar8 = extraout_ECX;
  pHVar9 = hdc;
  iVar5 = local_1c;
  FUN_42002e4a(&stack0xffffff54,(int *)&local_20);
  local_28 = FUN_4202aa79(*(void **)((int)local_14 + 0x40),*(int *)((int)local_14 + 0x14),iVar2,
                          iVar3,pOVar8,fVar4,pHVar9,iVar5,local_38,pLVar11);
  pOVar7 = (BSTR)(uint)(local_18 == 1);
  pOVar8 = pOVar7;
  FUN_42002e4a(&stack0xffffff60,(int *)&local_20);
  pvVar1 = local_14;
  local_2c = FUN_4202a8f1(*(void **)((int)local_14 + 0x40),*(int *)((int)local_14 + 0x14),iVar2,
                          iVar3,pOVar8,(char)pOVar7);
  FUN_4202aea0(*(int *)((int)pvVar1 + 0x40));
  DeleteDC(hdc);
  LVar6 = local_28;
  iVar5 = local_2c;
  if (local_18 != 0) {
    piVar12 = (int *)*param_4;
    piVar10 = param_3;
    iVar5 = local_1c;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    iVar5 = FUN_42003f6f(piVar12,piVar10,iVar5);
    iVar5 = local_2c + iVar5;
    LVar6 = local_28;
    if (local_28 < local_44[0]) {
      LVar6 = local_44[0];
    }
  }
  *param_1 = LVar6;
  param_1[1] = iVar5;
  if (local_24 == 0) {
    piVar12 = (int *)*param_3;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    iVar5 = FUN_42003ac3((int)*(double *)((int)local_14 + 0x30),1.4013e-45,piVar12);
    *param_1 = iVar5;
    piVar12 = (int *)*param_3;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    iVar5 = FUN_42003a36(*param_1,1.4013e-45,piVar12);
    *param_1 = iVar5;
    piVar12 = (int *)*param_3;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    fVar4 = 1.4013e-45;
    iVar5 = FUN_42004376(((double)*param_1 * (double)local_1c) / DAT_42089818);
    iVar5 = FUN_42003ac3(iVar5,fVar4,piVar12);
    *param_1 = iVar5;
  }
  if (local_24 == 0) {
    piVar12 = (int *)*param_3;
    if (piVar12 != (int *)0x0) {
      (**(code **)(*piVar12 + 4))();
    }
    FUN_42003a36(param_1[1],0.0,piVar12);
  }
  (**(code **)(*(int *)*param_4 + 0x84))();
  FUN_4205ed69(local_14,param_2,param_3,param_4);
  SysFreeString(local_20);
  local_8 = 0xffffffff;
  FUN_420030e8(local_44 + 2);
  return 0;
}


