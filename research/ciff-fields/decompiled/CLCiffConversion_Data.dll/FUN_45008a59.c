// Source: CLCiffConversion_Data.dll @ 45008a59; FUN_45008a59

wchar_t * __thiscall FUN_45008a59(void *this,wchar_t *param_1)

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
    if (-1 < iVar2) goto LAB_45008aab;
  }
  local_8 = this_00;
  piVar3 = FUN_4500839e(this,&DAT_45053868,&local_8);
  FUN_450051a0(this,&param_1,(int *)pwVar1,(wchar_t *)(piVar3 + 4),piVar3);
  pwVar1 = param_1;
LAB_45008aab:
  return pwVar1 + 0x14;
}


