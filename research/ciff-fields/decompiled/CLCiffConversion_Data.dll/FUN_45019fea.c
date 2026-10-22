// Source: CLCiffConversion_Data.dll @ 45019fea; FUN_45019fea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_45019fea(void *this,int param_1,BSTR param_2,BSTR param_3)

{
  UINT UVar1;
  int *piVar2;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR extraout_ECX_03;
  BSTR extraout_ECX_04;
  BSTR extraout_ECX_05;
  BSTR extraout_ECX_06;
  BSTR pOVar3;
  BSTR pOVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  
  iVar5 = 0;
  *(int *)this = param_1;
  pOVar4 = param_3;
  if (param_1 < 6) {
    if (param_1 == 5) {
      if (param_3 == (BSTR)0xffffffff) {
        pOVar4 = (BSTR)0xb;
      }
      UVar1 = SysStringLen(param_2);
      if (0xb < UVar1) {
        UVar1 = SysStringLen(param_2);
        bVar6 = UVar1 < 0xd;
        bVar7 = UVar1 == 0xd;
        pOVar3 = extraout_ECX_01;
LAB_4501a1af:
        if (bVar6 || bVar7) goto LAB_4501a171;
      }
    }
    else {
      if (param_1 == 0) {
        FUN_450022ea((void *)((int)this + 8),(int *)&param_2);
        pOVar4 = extraout_ECX_00;
        FUN_45001ef3(&stack0xffffffdc,(int *)&param_2);
        iVar5 = FUN_4501a1d3(this,pOVar4);
        goto LAB_4501a1c0;
      }
      if (param_1 == 3) {
LAB_4501a101:
        iVar5 = -1;
        goto LAB_4501a1c0;
      }
      if (param_1 != 4) goto LAB_4501a0ea;
      if (param_3 == (BSTR)0xffffffff) {
        pOVar4 = (BSTR)0x6;
      }
      UVar1 = SysStringLen(param_2);
      if (6 < UVar1) {
        UVar1 = SysStringLen(param_2);
        bVar6 = UVar1 < 8;
        bVar7 = UVar1 == 8;
        pOVar3 = extraout_ECX;
        goto LAB_4501a1af;
      }
    }
  }
  else if (param_1 == 6) {
    if (param_3 == (BSTR)0xffffffff) {
      pOVar4 = (BSTR)0xa;
    }
    UVar1 = SysStringLen(param_2);
    if (10 < UVar1) {
      UVar1 = SysStringLen(param_2);
      bVar6 = UVar1 < 0xc;
      bVar7 = UVar1 == 0xc;
      pOVar3 = extraout_ECX_06;
      goto LAB_4501a1af;
    }
  }
  else {
    if (param_1 == 7) {
      if (param_3 == (BSTR)0xffffffff) {
        pOVar4 = (BSTR)0xa;
      }
      UVar1 = SysStringLen(param_2);
      if ((UVar1 == 7) || (UVar1 = SysStringLen(param_2), pOVar3 = extraout_ECX_03, UVar1 == 8)) {
        FUN_450022ea((void *)((int)this + 0x10),(int *)&param_2);
        pOVar3 = extraout_ECX_04;
        FUN_45001ef3(&stack0xffffffdc,(int *)&param_2);
        piVar2 = (int *)FUN_4501b422(&param_3,pOVar3);
        FUN_450058c3(&param_2,piVar2);
        SysFreeString(param_3);
        FUN_450022ea((void *)((int)this + 8),(int *)&param_2);
        pOVar3 = extraout_ECX_05;
      }
LAB_4501a171:
      FUN_45001ef3(&stack0xffffffd8,(int *)&param_2);
      iVar5 = FUN_4501a2a2(this,pOVar3,(int)pOVar4);
      goto LAB_4501a1c0;
    }
    if (4 < param_1 - 10U) {
LAB_4501a0ea:
      FUN_450022ea((int *)((int)this + 8),(int *)&param_2);
      FUN_450022ea((void *)((int)this + 0xc),(int *)((int)this + 8));
      goto LAB_4501a101;
    }
    if (param_3 == (BSTR)0xffffffff) {
      pOVar4 = (BSTR)0xc;
    }
    UVar1 = SysStringLen(param_2);
    if (0xc < UVar1) {
      UVar1 = SysStringLen(param_2);
      bVar6 = UVar1 < 0xe;
      bVar7 = UVar1 == 0xe;
      pOVar3 = extraout_ECX_02;
      goto LAB_4501a1af;
    }
  }
  FUN_450022ea((void *)((int)this + 8),(int *)&param_2);
LAB_4501a1c0:
  SysFreeString(param_2);
  return iVar5;
}


