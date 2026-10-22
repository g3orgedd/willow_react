// Source: CLCiffConversion_Layout.dll @ 45427b1b; FUN_45427b1b

LSTATUS __thiscall FUN_45427b1b(void *this,LPCSTR param_1,BYTE *param_2)

{
  size_t sVar1;
  int iVar2;
  LSTATUS LVar3;
  BYTE *_Str;
  DWORD cbData;
  
  if (param_2 == (BYTE *)0x0) {
    LVar3 = 0xd;
  }
  else {
    cbData = 0;
    _Str = param_2;
    do {
      sVar1 = _strlen((char *)_Str);
      iVar2 = sVar1 + 1;
      _Str = _Str + iVar2;
      cbData = cbData + iVar2;
    } while (iVar2 != 1);
    LVar3 = RegSetValueExA(*(HKEY *)this,param_1,0,7,param_2,cbData);
  }
  return LVar3;
}


