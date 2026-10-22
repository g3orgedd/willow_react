// Source: CLCiffConversion_Data.dll @ 450058e9; FUN_450058e9

wchar_t * __thiscall FUN_450058e9(void *this,wchar_t *param_1)

{
  wchar_t *this_00;
  wchar_t *pwVar1;
  int iVar2;
  int *piVar3;
  wchar_t *local_8;
  
  this_00 = param_1;
  local_8 = this;
  pwVar1 = (wchar_t *)FUN_45007a11(this,param_1);
  if (pwVar1 != *(wchar_t **)this) {
    iVar2 = FUN_45007b0d(this_00,pwVar1 + 8);
    if (-1 < iVar2) goto LAB_4500593b;
  }
  local_8 = this_00;
  piVar3 = FUN_45004fee(this,&DAT_45053865,&local_8);
  FUN_450051a0(this,&param_1,(int *)pwVar1,(wchar_t *)(piVar3 + 4),piVar3);
  pwVar1 = param_1;
LAB_4500593b:
  return pwVar1 + 0x14;
}


