// Source: CiffMgr.dll @ 68117c0a; FUN_68117c0a

undefined4
FUN_68117c0a(void *param_1,BSTR param_2,short *param_3,BSTR param_4,BSTR param_5,undefined4 *param_6
            )

{
  BSTR pOVar1;
  undefined4 *puVar2;
  ushort uVar3;
  OLECHAR OVar4;
  UINT UVar5;
  undefined4 uVar6;
  code *pcVar7;
  BSTR pOVar8;
  uint uVar9;
  uint uVar10;
  
  FUN_68117de2(param_1,param_3,param_4,param_5 != (BSTR)0x0);
  uVar10 = 0;
  pOVar8 = (BSTR)0x0;
  param_4 = (BSTR)0x0;
  UVar5 = SysStringLen(param_2);
  param_5 = SysAllocStringLen((OLECHAR *)0x0,UVar5 / 3);
  pcVar7 = SysFreeString_exref;
  if (param_5 != (BSTR)0x0) {
    SysFreeString((BSTR)0x0);
    pOVar8 = param_5;
    param_4 = param_5;
    UVar5 = SysStringLen(param_2);
    pOVar1 = param_5;
    if (UVar5 / 3 != 0) {
      uVar9 = 0;
      do {
        uVar3 = FUN_68117b42((ushort *)(param_2 + uVar9 * 3));
        OVar4 = FUN_68117bea(param_1,uVar3);
        pOVar1[uVar9] = OVar4;
        uVar10 = uVar10 + 1;
        uVar9 = uVar10 & 0xffff;
        UVar5 = SysStringLen(param_2);
        pcVar7 = SysFreeString_exref;
        pOVar8 = param_4;
      } while (uVar9 < UVar5 / 3);
    }
    param_5[uVar10 & 0xffff] = L'\0';
  }
  puVar2 = param_6;
  (*pcVar7)(*param_6);
  uVar6 = FUN_681026d0(&param_4,puVar2);
  (*pcVar7)(pOVar8);
  return uVar6;
}


