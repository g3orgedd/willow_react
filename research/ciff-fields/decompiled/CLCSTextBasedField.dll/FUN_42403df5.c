// Source: CLCSTextBasedField.dll @ 42403df5; FUN_42403df5

long __thiscall FUN_42403df5(void *this,void *param_1,uint param_2)

{
  rsize_t rVar1;
  uint uVar2;
  uint ui;
  UINT UVar3;
  int iVar4;
  long lVar5;
  BSTR pOVar6;
  UINT UVar7;
  ulong local_c;
  ulong local_8;
  
  uVar2 = param_2;
  if ((param_1 != (void *)0x0) && ((*(int *)this == 0 || (param_2 != 0)))) {
    if ((int)param_2 < 0) {
      return -0x7ff8ffa9;
    }
    UVar3 = SysStringLen(*(BSTR *)this);
    local_8 = 0;
    param_2 = 0;
    local_c = 0;
    iVar4 = FUN_42403450((int *)&param_2,UVar3,uVar2);
    ui = param_2;
    if (iVar4 < 0) {
      return iVar4;
    }
    lVar5 = ATL::AtlMultiply<unsigned_long>(&local_c,param_2,2);
    if (lVar5 < 0) {
      return lVar5;
    }
    lVar5 = ATL::AtlMultiply<unsigned_long>(&local_8,UVar3,2);
    if (lVar5 < 0) {
      return lVar5;
    }
    pOVar6 = SysAllocStringLen((OLECHAR *)0x0,ui);
    if (pOVar6 == (BSTR)0x0) {
      return -0x7ff8fff2;
    }
    UVar7 = SysStringLen(*(BSTR *)this);
    if (UVar7 != 0) {
      FUN_42406d75(pOVar6,local_c,*(void **)this,local_8);
    }
    rVar1 = uVar2 * 2;
    FUN_42406d75(pOVar6 + UVar3,rVar1,param_1,rVar1);
    pOVar6[param_2] = L'\0';
    SysFreeString(*(BSTR *)this);
    *(BSTR *)this = pOVar6;
  }
  return 0;
}


