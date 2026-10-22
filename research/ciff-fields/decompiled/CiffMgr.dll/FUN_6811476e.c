// Source: CiffMgr.dll @ 6811476e; FUN_6811476e

HRESULT FUN_6811476e(SAFEARRAY *param_1,undefined4 *param_2)

{
  SAFEARRAY *psa;
  undefined4 *puVar1;
  HRESULT HVar2;
  UINT UVar3;
  BSTR pOVar4;
  int local_c;
  int *local_8;
  
  puVar1 = param_2;
  psa = param_1;
  if (param_1 == (SAFEARRAY *)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else if (param_2 == (undefined4 *)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else {
    UVar3 = SafeArrayGetDim(param_1);
    if (UVar3 == 1) {
      SafeArrayGetLBound(psa,1,&local_c);
      SafeArrayGetUBound(psa,1,(LONG *)&param_2);
      UVar3 = (int)param_2 + (1 - local_c);
      HVar2 = SafeArrayAccessData(psa,&param_1);
      if (-1 < HVar2) {
        if (*local_8 == 0) {
          pOVar4 = SysAllocStringLen((OLECHAR *)0x0,UVar3 * 2);
          *puVar1 = pOVar4;
          if (pOVar4 != (BSTR)0x0) {
            FUN_6811487e((int)param_1,UVar3,(int)pOVar4);
          }
        }
        else if (*local_8 == 1) {
          pOVar4 = SysAllocStringLen((OLECHAR *)0x0,UVar3);
          *puVar1 = pOVar4;
          if (pOVar4 != (BSTR)0x0) {
            FUN_6811483a((int)param_1,UVar3,(int)pOVar4);
          }
        }
        HVar2 = SafeArrayUnaccessData(psa);
      }
    }
    else {
      HVar2 = -0x7ff8ffa9;
    }
  }
  return HVar2;
}


