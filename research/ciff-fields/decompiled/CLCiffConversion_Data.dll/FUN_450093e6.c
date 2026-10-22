// Source: CLCiffConversion_Data.dll @ 450093e6; FUN_450093e6

undefined4 __cdecl FUN_450093e6(undefined4 *param_1)

{
  OLECHAR OVar1;
  UINT UVar2;
  undefined4 uVar3;
  uint uVar4;
  
  UVar2 = SysStringLen((BSTR)*param_1);
  if (UVar2 == 0) {
    uVar3 = 0x80070057;
  }
  else {
    uVar4 = 0;
    UVar2 = SysStringLen((BSTR)*param_1);
    if (UVar2 != 0) {
      do {
        OVar1 = ((BSTR)*param_1)[uVar4];
        if (((ushort)OVar1 < 0x30) || (0x39 < (ushort)OVar1)) {
          return 0x80004005;
        }
        uVar4 = uVar4 + 1;
        UVar2 = SysStringLen((BSTR)*param_1);
      } while (uVar4 < UVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}


