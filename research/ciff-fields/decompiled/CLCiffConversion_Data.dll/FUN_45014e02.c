// Source: CLCiffConversion_Data.dll @ 45014e02; FUN_45014e02

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45014e02(void *this,wchar_t *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    uVar1 = 0;
  }
  else {
    sVar2 = _wcslen(param_1);
    uVar1 = FUN_450152b1(this,param_1,sVar2);
  }
  return uVar1;
}


