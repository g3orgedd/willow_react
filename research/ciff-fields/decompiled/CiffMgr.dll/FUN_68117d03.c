// Source: CiffMgr.dll @ 68117d03; FUN_68117d03

undefined4
FUN_68117d03(void *param_1,BSTR param_2,short *param_3,BSTR param_4,BSTR param_5,undefined4 *param_6
            )

{
  undefined4 *puVar1;
  ushort uVar2;
  UINT UVar3;
  OLECHAR *pOVar4;
  BSTR pOVar5;
  code *pcVar6;
  BSTR pOVar7;
  uint uVar8;
  
  FUN_68117de2(param_1,param_3,param_4,param_5 != (BSTR)0x0);
  uVar8 = 0;
  param_4 = (BSTR)0x0;
  UVar3 = SysStringLen(param_2);
  param_5 = SysAllocStringLen((OLECHAR *)0x0,UVar3 * 3);
  pcVar6 = SysFreeString_exref;
  pOVar7 = (BSTR)0x0;
  if (param_5 != (BSTR)0x0) {
    SysFreeString((BSTR)0x0);
    param_4 = param_5;
    pOVar7 = param_5;
  }
  UVar3 = SysStringLen(param_2);
  if (UVar3 != 0) {
    param_5 = (BSTR)0x0;
    do {
      uVar2 = FUN_68117ce1(param_1,param_2[(int)param_5]);
      pOVar4 = FUN_68117b8e(param_1,(uint)uVar2);
      uVar8 = uVar8 + 1;
      pOVar7[(int)param_5 * 3] = *pOVar4;
      pOVar7[(int)param_5 * 3 + 1] = pOVar4[1];
      pOVar7[(int)param_5 * 3 + 2] = pOVar4[2];
      param_5 = (BSTR)(uVar8 & 0xffff);
      pOVar5 = (BSTR)SysStringLen(param_2);
      pcVar6 = SysFreeString_exref;
    } while (param_5 < pOVar5);
  }
  puVar1 = param_6;
  pOVar7[(uVar8 & 0xffff) * 3] = L'\0';
  (*pcVar6)(*param_6);
  FUN_681026d0(&param_4,puVar1);
  (*pcVar6)(pOVar7);
  return 0;
}


