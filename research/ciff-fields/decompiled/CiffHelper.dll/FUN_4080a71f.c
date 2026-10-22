// Source: CiffHelper.dll @ 4080a71f; FUN_4080a71f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4080a71f(void *this,undefined4 *param_1)

{
  int local_134;
  wchar_t *local_130;
  wchar_t local_12c [128];
  wchar_t local_2c [18];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x124;
  local_8 = 0x4080a72e;
  if (*(int *)((int)this + 0x54) != 0) {
    local_130 = local_12c;
    ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_130,(wchar_t *)*param_1);
    local_8 = 0;
    basic_string<>(local_2c,local_130);
    if (local_130 != local_12c) {
      FID_conflict__free(local_130);
    }
    FUN_4080bddd((void *)((int)this + 0x50),&local_134,local_2c);
    FUN_4080653d(local_2c,'\x01',0);
  }
  FUN_4082d4c6();
  return;
}


