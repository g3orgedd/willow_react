// Source: CLCiffConversion_Data.dll @ 4501bfd4; FUN_4501bfd4

undefined4 FUN_4501bfd4(UINT param_1,int *param_2,OLECHAR param_3)

{
  UINT UVar1;
  BSTR pOVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  BSTR pOVar7;
  BSTR local_8;
  
  uVar4 = 0;
  if (((int)param_1 < 1) || (param_3 == L'\0')) {
    uVar4 = 0x80070057;
  }
  else {
    UVar1 = SysStringLen((BSTR)*param_2);
    iVar5 = UVar1 - param_1;
    if (iVar5 < 1) {
      if (-1 < iVar5) {
        return 1;
      }
      uVar6 = -iVar5;
      pOVar2 = SysAllocStringLen((OLECHAR *)0x0,param_1);
      if (pOVar2 != (BSTR)0x0) {
        local_8 = pOVar2;
        if (0 < (int)uVar6) {
          pOVar7 = pOVar2;
          for (uVar3 = uVar6 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(uint *)pOVar7 = CONCAT22(param_3,param_3);
            pOVar7 = pOVar7 + 2;
          }
          for (uVar6 = (uint)((uVar6 & 1) != 0); uVar6 != 0; uVar6 = uVar6 - 1) {
            *pOVar7 = param_3;
            pOVar7 = pOVar7 + 1;
          }
          local_8 = pOVar2 + -iVar5;
        }
        UVar1 = SysStringLen((BSTR)*param_2);
        FUN_45021540((undefined8 *)local_8,(undefined8 *)*param_2,UVar1 * 2);
        pOVar2[param_1] = L'\0';
      }
    }
    else {
      pOVar2 = SysAllocString((OLECHAR *)(*param_2 + iVar5 * 2));
    }
    SysFreeString((BSTR)*param_2);
    *param_2 = 0;
    if (pOVar2 != (BSTR)0x0) {
      SysFreeString((BSTR)0x0);
      *param_2 = (int)pOVar2;
    }
  }
  return uVar4;
}


