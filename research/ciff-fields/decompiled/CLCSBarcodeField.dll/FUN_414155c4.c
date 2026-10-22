// Source: CLCSBarcodeField.dll @ 414155c4; FUN_414155c4

void FUN_414155c4(undefined4 *param_1,BSTR param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  OLECHAR local_24 [2];
  wchar_t local_20 [2];
  wchar_t local_1c [3];
  undefined2 local_16;
  undefined2 local_14;
  OLECHAR local_10;
  OLECHAR local_e;
  wchar_t local_c [2];
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  *param_1 = 0;
  local_24[0] = param_2[6];
  uVar1 = (uint)(ushort)local_24[0];
  local_24[1] = 0;
  if (uVar1 == 0x33) {
    FUN_41462634(local_1c,5,param_2,4);
    local_14 = 0;
    FUN_4140363d(param_1,local_1c);
    FUN_4140363d(param_1,L"00000");
    local_10 = param_2[4];
    local_e = param_2[5];
    local_c[0] = L'\0';
    pwVar2 = &local_10;
  }
  else if (uVar1 == 0x34) {
    FUN_41462634(local_20,6,param_2,5);
    local_16 = 0;
    FUN_4140363d(param_1,local_20);
    FUN_4140363d(param_1,L"00000");
    local_c[0] = param_2[5];
    local_c[1] = 0;
    pwVar2 = local_c;
  }
  else if (uVar1 - 0x35 < 5) {
    FUN_41462634(local_20,7,param_2,6);
    local_14 = 0;
    FUN_4140363d(param_1,local_20);
    FUN_4140363d(param_1,L"0000");
    pwVar2 = local_24;
  }
  else {
    FUN_41462634(local_1c,4,param_2,3);
    local_16 = 0;
    FUN_4140363d(param_1,local_1c);
    FUN_4140363d(param_1,local_24);
    FUN_4140363d(param_1,L"0000");
    local_10 = param_2[3];
    local_e = param_2[4];
    local_c[0] = param_2[5];
    local_c[1] = 0;
    pwVar2 = &local_10;
  }
  FUN_4140363d(param_1,pwVar2);
  SysFreeString(param_2);
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


