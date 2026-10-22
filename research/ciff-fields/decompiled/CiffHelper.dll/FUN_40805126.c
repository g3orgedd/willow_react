// Source: CiffHelper.dll @ 40805126; FUN_40805126

HRESULT __thiscall FUN_40805126(void *this,IID *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x54))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_4084a800);
  }
  return iVar1;
}


