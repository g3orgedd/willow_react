// Source: CLCiffConversion_Data.dll @ 450020a5; FUN_450020a5

undefined4 * __thiscall FUN_450020a5(void *this,LPCWSTR param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_4505101c;
  if (param_1 != (LPCWSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_45003f80(this,(uint)param_1 & 0xffff);
    }
    else {
      iVar1 = lstrlenW(param_1);
      if ((iVar1 != 0) && (iVar2 = FUN_4500244d(this,iVar1), iVar2 != 0)) {
        FUN_45004ebd(*(void **)this,iVar1 * 2 + 2,param_1,iVar1 * 2);
      }
    }
  }
  return this;
}


