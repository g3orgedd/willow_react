// Source: CLARiSOFT.exe @ 00e03c2c; FUN_00e03c2c

undefined4 * __thiscall FUN_00e03c2c(void *this,LPCSTR param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  uVar1 = ConvertStringToBSTR(param_1);
  *(undefined4 *)this = uVar1;
  return this;
}


