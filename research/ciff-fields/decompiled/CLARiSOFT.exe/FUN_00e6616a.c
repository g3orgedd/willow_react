// Source: CLARiSOFT.exe @ 00e6616a; FUN_00e6616a

undefined4 __thiscall FUN_00e6616a(void *this,BSTR param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != (BSTR)0x0) {
    uVar1 = FUN_00e678db(this,param_1);
    (**(code **)(*(int *)param_1 + 0xc))(1);
    FUN_00e677b0(this,'\0');
  }
  return uVar1;
}


