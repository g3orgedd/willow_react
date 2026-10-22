// Source: CLCSTextBasedField.dll @ 4240391a; FUN_4240391a

undefined4 * __thiscall FUN_4240391a(void *this,LPCWSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_424b9014;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_42405cba(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if ((iVar1 != 0) && (iVar2 = FUN_42403cf7(this,iVar1), iVar2 != 0)) {
        FUN_42406d75(*(void **)this,iVar1 * 2 + 2,param_1,iVar1 * 2);
      }
    }
  }
  return this;
}


