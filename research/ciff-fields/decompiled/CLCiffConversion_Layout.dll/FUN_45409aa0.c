// Source: CLCiffConversion_Layout.dll @ 45409aa0; FUN_45409aa0

bool __thiscall FUN_45409aa0(void *this,undefined4 *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VarBstrCmp(*(BSTR *)this,(BSTR)*param_1,0x400,0);
  return (bool)('\x01' - (HVar1 != 2));
}


