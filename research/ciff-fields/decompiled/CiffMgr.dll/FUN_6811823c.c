// Source: CiffMgr.dll @ 6811823c; FUN_6811823c

HRESULT __thiscall FUN_6811823c(void *this,BSTR param_1)

{
  UINT UVar1;
  HRESULT HVar2;
  BSTR local_8;
  
  local_8 = this;
  UVar1 = SysStringLen(param_1);
  HVar2 = 0;
  if (UVar1 != 0) {
    local_8 = (BSTR)0x0;
    HVar2 = VarBstrCat(*(BSTR *)this,param_1,&local_8);
    if (-1 < HVar2) {
      SysFreeString(*(BSTR *)this);
      *(BSTR *)this = local_8;
    }
  }
  return HVar2;
}


