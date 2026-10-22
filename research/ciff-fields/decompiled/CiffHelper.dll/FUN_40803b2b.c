// Source: CiffHelper.dll @ 40803b2b; FUN_40803b2b

undefined4 * __thiscall FUN_40803b2b(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  code *pcVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)this = 0;
  HVar2 = FUN_4080503b(this,param_1,param_2,param_3);
  if ((HVar2 < 0) && (HVar2 != -0x7fffbffe)) {
    _com_issue_error(HVar2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return this;
}


