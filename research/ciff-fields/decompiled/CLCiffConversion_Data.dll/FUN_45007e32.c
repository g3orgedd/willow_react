// Source: CLCiffConversion_Data.dll @ 45007e32; FUN_45007e32

void __thiscall FUN_45007e32(void *this,int *param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  
  pwVar1 = (wchar_t *)FUN_45007a11(this,param_2);
  if ((pwVar1 == *(wchar_t **)this) ||
     (iVar2 = FUN_45007b0d(param_2,pwVar1 + 8), param_2 = pwVar1, iVar2 < 0)) {
    param_2 = *(wchar_t **)this;
  }
  *param_1 = (int)param_2;
  return;
}


