// Source: CiffMgr.dll @ 68108e93; FUN_68108e93

int FUN_68108e93(BSTR param_1,BSTR param_2)

{
  UINT UVar1;
  UINT UVar2;
  int iVar3;
  BSTR pOVar4;
  
  UVar1 = SysStringLen(param_1);
  UVar2 = SysStringLen(param_2);
  if (UVar1 < UVar2) {
    iVar3 = -1;
  }
  else if (UVar2 < UVar1) {
    iVar3 = 1;
  }
  else {
    if ((UVar1 != 0) && (iVar3 = UVar1 - 1, -1 < iVar3)) {
      pOVar4 = param_2 + iVar3;
      do {
        if (*(OLECHAR *)(((int)param_1 - (int)param_2) + (int)pOVar4) != *pOVar4) {
          return (uint)(ushort)param_1[iVar3] - (uint)(ushort)param_2[iVar3];
        }
        pOVar4 = pOVar4 + -1;
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
    }
    iVar3 = 0;
  }
  return iVar3;
}


