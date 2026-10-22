// Source: CLARiSOFT.exe @ 00e029ff; FUN_00e029ff

undefined4 * __thiscall FUN_00e029ff(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  HRESULT HVar1;
  
  *(undefined4 *)this = 0;
  HVar1 = FUN_00e04f7b(this,param_1,param_2,param_3);
  if ((HVar1 < 0) && (HVar1 != -0x7fffbffe)) {
                    /* WARNING: Subroutine does not return */
    _com_issue_error(HVar1);
  }
  return this;
}


