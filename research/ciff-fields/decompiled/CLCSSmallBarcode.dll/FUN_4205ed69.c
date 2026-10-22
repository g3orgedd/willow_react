// Source: CLCSSmallBarcode.dll @ 4205ed69; FUN_4205ed69

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_4205ed69(void *this,BSTR param_1,int *param_2,int *param_3)

{
  BSTR pOVar1;
  BSTR pOVar2;
  BSTR pOVar3;
  int iVar4;
  float10 fVar5;
  double dVar6;
  char cVar7;
  int *piVar8;
  int *piVar9;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  BSTR local_24;
  int local_20;
  HDC local_1c;
  int local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4205ed75;
  FUN_42002e41(&local_3c);
  local_8 = 0;
  (**(code **)(*(int *)*param_3 + 0xb0))();
  (**(code **)(**(int **)param_1 + 0x54))();
  local_20 = 0;
  (**(code **)(*(int *)*param_3 + 0xc0))();
  local_1c = GetDC((HWND)0x0);
  local_14[0] = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*(int *)*param_3 + 0x98))();
  local_28 = 0;
  if (local_20 == 1) {
    piVar8 = (int *)*param_3;
    piVar9 = param_2;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 4))();
    }
    local_28 = FUN_42003f6f(piVar8,piVar9,local_30);
  }
  (**(code **)(*(int *)*param_2 + 0x2c))();
  (**(code **)(*(int *)*param_3 + 0x78))();
  dVar6 = (double)local_34;
  if (local_18 == 1) {
    dVar6 = dVar6 / (double)(float)param_1;
  }
  dVar6 = (dVar6 * DAT_42089818) / *(double *)((int)this + 0x30);
  if (_DAT_4209e1b0 < dVar6) {
    fVar5 = FUN_42066adf((int)this,param_2);
    dVar6 = (double)fVar5;
  }
  local_2c = FUN_42004376(((*(double *)((int)this + 0x28) * dVar6) / DAT_42089818) *
                          (double)(float)param_1);
  if (local_2c < 1) {
    local_2c = 1;
  }
  (**(code **)(*(int *)*param_3 + 0x80))();
  pOVar1 = local_24;
  if (local_18 == 0) {
    piVar8 = (int *)*param_2;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 4))();
    }
    pOVar1 = (BSTR)FUN_42003ac3((int)pOVar1,0.0,piVar8);
  }
  iVar4 = *(int *)((int)this + 0x14);
  local_38 = 0;
  if ((iVar4 < 10) || ((0xb < iVar4 && (1 < iVar4 - 0xdU)))) goto LAB_4205ef8d;
  param_1 = (BSTR)0x0;
  if (*(int *)((int)this + 0x40) != 0) {
    cVar7 = '\0';
    FUN_42002e4a(&stack0xffffff68,(int *)local_14);
    pOVar2 = (BSTR)FUN_4202a8f1(*(void **)((int)this + 0x40),*(int *)((int)this + 0x14),local_2c,
                                (int)pOVar1,local_24,cVar7);
    if (pOVar2 != (BSTR)0x0) {
      iVar4 = (int)pOVar1 - local_28;
      do {
        pOVar3 = pOVar2;
        pOVar2 = pOVar3;
        if ((int)pOVar3 <= iVar4) break;
        pOVar1 = (BSTR)((int)pOVar1 + -1);
        cVar7 = '\0';
        FUN_42002e4a(&stack0xffffff68,(int *)local_14);
        pOVar2 = (BSTR)FUN_4202a8f1(*(void **)((int)this + 0x40),*(int *)((int)this + 0x14),local_2c
                                    ,(int)pOVar1,param_1,cVar7);
        param_1 = pOVar3;
      } while (pOVar2 != pOVar3);
      if (pOVar2 != param_1) goto LAB_4205ef62;
    }
    pOVar1 = (BSTR)((int)pOVar1 + 1);
  }
LAB_4205ef62:
  if (local_18 == 0) {
    piVar8 = (int *)*param_2;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 4))();
    }
    FUN_42003a36((int)pOVar1,0.0,piVar8);
  }
LAB_4205ef8d:
  (**(code **)(*(int *)*param_3 + 0xbc))();
  ReleaseDC((HWND)0x0,local_1c);
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  FUN_420030e8(&local_3c);
  return;
}


