// Source: CiffHelper.dll @ 4081d4fb; FUN_4081d4fb

void FUN_4081d4fb(int *param_1)

{
  uint uVar1;
  OLECHAR *strIn;
  UINT UVar2;
  short *psVar3;
  BSTR pOVar4;
  uint uVar5;
  
  UVar2 = SysStringLen((BSTR)*param_1);
  if (UVar2 != 0) {
    uVar1 = UVar2 - 1;
    uVar5 = uVar1;
    if (uVar1 != 0) {
      psVar3 = (short *)(*param_1 + uVar1 * 2);
      do {
        if (*psVar3 != 0x20) break;
        psVar3 = psVar3 + -1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    if (uVar5 < uVar1) {
      strIn = (OLECHAR *)*param_1;
      *param_1 = 0;
      pOVar4 = SysAllocStringLen(strIn,uVar5 + 1);
      if ((BSTR)*param_1 != pOVar4) {
        SysFreeString((BSTR)*param_1);
        *param_1 = (int)pOVar4;
      }
      SysFreeString(strIn);
    }
  }
  return;
}


