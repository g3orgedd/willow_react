// Source: CLCiffConversion_Data.dll @ 4500376b; FUN_4500376b

HRESULT __thiscall FUN_4500376b(void *this,IID *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x54))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_4503d550);
  }
  return iVar1;
}


