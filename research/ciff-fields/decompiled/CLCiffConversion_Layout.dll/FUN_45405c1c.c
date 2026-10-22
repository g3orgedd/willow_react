// Source: CLCiffConversion_Layout.dll @ 45405c1c; FUN_45405c1c

HRESULT __thiscall FUN_45405c1c(void *this,IID *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x54))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_45447bac);
  }
  return iVar1;
}


