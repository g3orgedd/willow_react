// Source: CiffMgr.dll @ 68114633; FUN_68114633

HRESULT __thiscall FUN_68114633(void *this,BSTR param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  UINT UVar3;
  SAFEARRAY *psa;
  SAFEARRAYBOUND local_c;
  
  puVar1 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else if (param_1 == (BSTR)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else {
    local_c.cElements = (ULONG)this;
    local_c.lLbound = (LONG)this;
    UVar3 = SysStringLen(param_1);
    local_c.lLbound = 0;
    local_c.cElements = UVar3;
    if (*(int *)this == 0) {
      local_c.cElements = UVar3 >> 1;
    }
    psa = SafeArrayCreate(0x11,1,&local_c);
    *puVar1 = psa;
    if (psa == (SAFEARRAY *)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      param_2 = (undefined4 *)0x0;
      HVar2 = SafeArrayAccessData(psa,&param_2);
      if ((HVar2 < 0) || (param_2 == (undefined4 *)0x0)) {
        HVar2 = SafeArrayDestroy((SAFEARRAY *)*puVar1);
        *puVar1 = 0;
      }
      else {
        if (*(int *)this == 0) {
          FUN_68114726((ushort *)param_1,UVar3,(int)param_2);
        }
        else if (*(int *)this == 1) {
          FUN_681146ee((int)param_1,UVar3,(int)param_2);
        }
        HVar2 = SafeArrayUnaccessData((SAFEARRAY *)*puVar1);
      }
    }
  }
  return HVar2;
}


