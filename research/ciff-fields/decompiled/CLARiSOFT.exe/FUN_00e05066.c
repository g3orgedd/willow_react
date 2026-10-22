// Source: CLARiSOFT.exe @ 00e05066; FUN_00e05066

HRESULT __thiscall FUN_00e05066(void *this,IID *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x54))(this,param_1);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_00efcb78);
  }
  return iVar1;
}


