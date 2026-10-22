// Source: CLCiffConversion_Data.dll @ 45009989; FUN_45009989

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __cdecl FUN_45009989(undefined4 param_1,undefined4 *param_2,BSTR param_3,VARIANTARG *param_4)

{
  int iVar1;
  BSTR pOVar2;
  VARIANTARG *pVVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  _union_2683 local_30;
  int local_20;
  int local_1c;
  void *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pVVar3 = param_4;
  uStack_4 = 0x20;
  local_8 = 0x45009995;
  bVar9 = false;
  if (param_3 == (BSTR)0x0) {
    if ((param_4->n1).n2.vt != 3) {
      return 0x80070057;
    }
    param_3 = (BSTR)0x0;
    uVar8 = (**(code **)(*(int *)*param_2 + 0x50))((int *)*param_2,&param_3);
    if ((int)uVar8 < 0) {
      return uVar8;
    }
    pOVar2 = *(BSTR *)((int)&pVVar3->n1 + 8);
    if ((int)pOVar2 < 0) {
      return 0x80070057;
    }
    bVar4 = SBORROW4((int)pOVar2,(int)param_3);
    iVar5 = (int)pOVar2 - (int)param_3;
    bVar9 = pOVar2 == param_3;
  }
  else {
    if (param_3 != (BSTR)0x1) {
      if (param_3 != (BSTR)0x2) {
        if (param_3 != (BSTR)0x4) {
          return 0x80070057;
        }
        if ((param_4->n1).n2.vt != 8) {
          VariantChangeType(param_4,param_4,0,8);
        }
        FUN_45001f5d(&param_3,*(OLECHAR **)((int)&pVVar3->n1 + 8));
        local_8 = 2;
        FUN_45001f8d((uint *)&local_30);
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar5 = (**(code **)(*(int *)*param_2 + 0x60))((int *)*param_2,&local_30);
        if ((-1 < iVar5) && (local_30.n2.vt == 0x2008)) {
          uVar8 = ((SAFEARRAYBOUND *)(local_30._8_4_ + 0x10))->cElements;
          local_18 = (void *)0x0;
          SafeArrayAccessData((SAFEARRAY *)local_30._8_4_,&local_18);
          uVar7 = 0;
          if (uVar8 != 0) {
            do {
              bVar4 = FUN_450023b0(&param_3,*(OLECHAR **)((int)local_18 + uVar7 * 4));
              if (bVar4) {
                bVar9 = true;
                break;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar8);
          }
          SafeArrayUnaccessData((SAFEARRAY *)local_30._8_4_);
        }
        uVar8 = 0x80070057;
        if (bVar9) {
          uVar8 = 0;
        }
        VariantClear((VARIANTARG *)&local_30.n2);
        SysFreeString(param_3);
        return uVar8;
      }
      if ((param_4->n1).n2.vt != 8) {
        VariantChangeType(param_4,param_4,0,8);
      }
      FUN_45001f5d(local_14,*(OLECHAR **)((int)&pVVar3->n1 + 8));
      local_8 = 0;
      local_18 = (void *)SysStringLen(local_14[0]);
      local_1c = 0;
      local_20 = 0;
      param_3 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      uVar8 = (**(code **)(*(int *)*param_2 + 0x48))((int *)*param_2,&local_1c);
      uVar7 = (**(code **)(*(int *)*param_2 + 0x50))((int *)*param_2,&local_20);
      uVar6 = (**(code **)(*(int *)*param_2 + 0x68))((int *)*param_2,&param_3);
      uVar6 = uVar8 | uVar7 | uVar6;
      if (-1 < (int)uVar6) {
        if ((local_1c <= (int)local_18) && ((int)local_18 <= local_20)) {
          iVar5 = FUN_45009814((int *)local_14,(int *)&param_3);
          uVar6 = 0;
          if (iVar5 == 0) goto LAB_45009b02;
        }
        uVar6 = 0x80070057;
      }
LAB_45009b02:
      SysFreeString(param_3);
      SysFreeString(local_14[0]);
      return uVar6;
    }
    if ((param_4->n1).n2.vt != 3) {
      return 0x80070057;
    }
    param_3 = (BSTR)0x0;
    local_20 = 0;
    uVar8 = (**(code **)(*(int *)*param_2 + 0x48))((int *)*param_2,&param_3);
    uVar7 = (**(code **)(*(int *)*param_2 + 0x50))((int *)*param_2,&local_20);
    if ((int)(uVar8 | uVar7) < 0) {
      return uVar8 | uVar7;
    }
    iVar1 = *(int *)((int)&param_4->n1 + 8);
    if (iVar1 < (int)param_3) {
      return 0x80070057;
    }
    bVar4 = SBORROW4(iVar1,local_20);
    iVar5 = iVar1 - local_20;
    bVar9 = iVar1 == local_20;
  }
  if (!bVar9 && bVar4 == iVar5 < 0) {
    return 0x80070057;
  }
  return 0;
}


