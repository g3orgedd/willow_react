// Source: CiffHelper.dll @ 408240f3; FUN_408240f3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

BSTR __thiscall FUN_408240f3(void *this,int *param_1)

{
  int *piVar1;
  char cVar2;
  BSTR pOVar3;
  int iVar4;
  UINT UVar5;
  BSTR extraout_EAX;
  BSTR bstrString;
  int *piVar6;
  BSTR *ppOVar7;
  _union_2683 local_4c;
  _union_2683 local_3c;
  _union_2683 local_2c;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x408240ff;
  CComQIPtr<>(&param_1,(undefined4 *)*param_1);
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    pOVar3 = (BSTR)0x80070057;
  }
  else {
    piVar6 = (int *)((int)this + 8);
    *piVar6 = 0;
    pOVar3 = (BSTR)(**(code **)(*param_1 + 0xd0))();
    if ((-1 < (int)pOVar3) && (*piVar6 < 0x18)) {
      piVar1 = (int *)((int)this + 0xc);
      SysFreeString((BSTR)*piVar1);
      *piVar1 = 0;
      pOVar3 = (BSTR)(**(code **)(*param_1 + 0x44))();
      if (-1 < (int)pOVar3) {
        local_1c = (BSTR)0x0;
        ppOVar7 = &local_1c;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_40803baf(&stack0xffffff9c,piVar1);
        iVar4 = FUN_40823bfb(this,pOVar3,ppOVar7);
        pOVar3 = local_1c;
        bstrString = pOVar3;
        if ((-1 < iVar4) && (UVar5 = SysStringLen(local_1c), UVar5 != 0)) {
          (**(code **)(*param_1 + 0x48))();
          SysFreeString(*(BSTR *)((int)this + 0xc));
          piVar1 = (int *)((int)this + 0xc);
          *piVar1 = 0;
          bstrString = (BSTR)0x0;
          local_18 = pOVar3;
          local_1c = (BSTR)0x0;
          if ((BSTR)*piVar1 != pOVar3) {
            SysFreeString((BSTR)*piVar1);
            *(BSTR *)((int)this + 0xc) = local_18;
          }
        }
        FUN_40802e76((uint *)&local_3c);
        local_8 = CONCAT31(local_8._1_3_,2);
        iVar4 = (**(code **)(*param_1 + 100))();
        if (((iVar4 < 0) || (local_3c.n2.vt != 9)) ||
           ((((*(code *)**(undefined4 **)local_3c._8_4_)(local_3c._8_4_), 9 < *piVar6 ||
             (local_14 = (BSTR)FUN_4082461d((int *)&param_1), -1 < (int)local_14)) &&
            ((0xb < *(int *)((int)this + 8) ||
             (local_14 = (BSTR)FUN_4082484c((BSTR)&param_1), -1 < (int)local_14)))))) {
          FUN_40802e76((uint *)&local_2c);
          local_8 = CONCAT31(local_8._1_3_,3);
          iVar4 = (**(code **)(*param_1 + 0xcc))();
          if (((iVar4 < 0) || (local_2c.n2.vt != 9)) ||
             ((((*(code *)**(undefined4 **)local_2c._8_4_)(local_2c._8_4_),
               9 < *(int *)((int)this + 8) ||
               (local_14 = (BSTR)FUN_40824968((LPCWSTR)&param_1), -1 < (int)local_14)) &&
              ((0xb < *(int *)((int)this + 8) ||
               (local_14 = (BSTR)FUN_40824b5d((BSTR)&param_1), -1 < (int)local_14)))))) {
            piVar6 = (int *)((int)this + 8);
            FUN_40825e11(this,&param_1);
            FUN_40802e76((uint *)&local_4c);
            local_8._0_1_ = 4;
            local_14 = (BSTR)(**(code **)(*param_1 + 0x80))();
            if (((-1 < (int)local_14) && (local_4c.n2.vt == 9)) &&
               ((undefined4 *)local_4c._8_4_ != (undefined4 *)0x0)) {
              local_18 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,5);
              local_14 = (BSTR)(*(code *)**(undefined4 **)local_4c._8_4_)(local_4c._8_4_);
              if ((-1 < (int)local_14) && (local_18 != (BSTR)0x0)) {
                if (*piVar6 < 9) {
                  local_14 = (BSTR)FUN_40825635(this,(int *)&local_18);
                }
                if ((*piVar6 < 0xe) &&
                   (cVar2 = FUN_40823bad((void *)((int)this + 0xc)), cVar2 != '\0')) {
                  this = (void *)FUN_408268cb((int *)&local_18);
                  local_14 = extraout_EAX;
                }
                if (*piVar6 < 0x17) {
                  local_14 = (BSTR)FUN_4082577b((int *)&param_1,&local_18);
                }
              }
              local_8._0_1_ = 4;
              if (local_18 != (BSTR)0x0) {
                (**(code **)(*(int *)local_18 + 8))();
              }
            }
            VariantClear((VARIANTARG *)&local_4c.n2);
            VariantClear((VARIANTARG *)&local_2c.n2);
            VariantClear((VARIANTARG *)&local_3c.n2);
            local_8 = (uint)local_8._1_3_ << 8;
            SysFreeString(bstrString);
            pOVar3 = local_14;
            if (-1 < (int)local_14) {
              if (*(int *)((int)this + 8) < 0x10) {
                FUN_408237fd((BSTR)&param_1);
              }
              if (*(int *)((int)this + 8) < 0x10) {
                FUN_40823a70((BSTR)&param_1);
              }
              if (*(int *)((int)this + 8) < 0x11) {
                FUN_40823c82((BSTR)&param_1);
              }
              local_14 = (BSTR)(**(code **)(*param_1 + 0xd4))();
              pOVar3 = local_14;
            }
            goto LAB_40824414;
          }
          VariantClear((VARIANTARG *)&local_2c.n2);
        }
        VariantClear((VARIANTARG *)&local_3c.n2);
        SysFreeString(bstrString);
        pOVar3 = local_14;
        goto LAB_4082443a;
      }
    }
  }
LAB_40824414:
  piVar6 = *(int **)this;
  if (piVar6 != (int *)0x0) {
    *(int *)this = 0;
    (**(code **)(*piVar6 + 8))();
  }
  piVar6 = *(int **)((int)this + 4);
  if (piVar6 != (int *)0x0) {
    *(int *)((int)this + 4) = 0;
    (**(code **)(*piVar6 + 8))();
  }
LAB_4082443a:
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return pOVar3;
}


