// Source: CLCiffConversion_Layout.dll @ 45402a65; FUN_45402a65

undefined4 * __thiscall FUN_45402a65(void *this,LPCSTR param_1)

{
  rsize_t rVar1;
  int iVar2;
  
  *(undefined **)this = PTR_DAT_4545d110;
  if (param_1 != (LPCSTR)0x0) {
    if ((short)((uint)param_1 >> 0x10) == 0) {
      FUN_45403ea7(this,(uint)param_1 & 0xffff);
    }
    else {
      rVar1 = lstrlenA(param_1);
      if ((rVar1 != 0) && (iVar2 = FUN_45402e54(this,rVar1), iVar2 != 0)) {
        FUN_45404b24(*(void **)this,rVar1 + 1,param_1,rVar1);
      }
    }
  }
  return this;
}


