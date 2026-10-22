// Source: CLCiffConversion_Data.dll @ 4501f615; FUN_4501f615

void __fastcall FUN_4501f615(void *param_1)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  uint uVar4;
  wchar_t *pwVar5;
  wchar_t awStackY_8c [22];
  undefined4 uStackY_60;
  double local_3c;
  uint local_34;
  int local_30;
  wchar_t local_2c [12];
  wchar_t local_14 [6];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  pwVar3 = L"ABCDEFGHIJ";
  pwVar5 = local_2c;
  for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pwVar5 = *(undefined4 *)pwVar3;
    pwVar3 = pwVar3 + 2;
    pwVar5 = pwVar5 + 2;
  }
  *pwVar5 = *pwVar3;
  iVar2 = FUN_45022b22((wchar_t *)((int)param_1 + 0xfc),0x450416b0);
  if (((iVar2 == 2) && (local_30 - 1U < 0x3c)) && (local_34 < 0x10)) {
    local_3c = *(double *)((int)param_1 + 0xb0);
    uVar4 = 0;
    if (*(int *)((int)param_1 + 0xf8) == 4) {
      FUN_4501de09(&local_3c);
      _swprintf_s(local_14,5,L"%02ld");
    }
    else if (*(int *)((int)param_1 + 0xf8) == 6) {
      FUN_4501ddb8(&local_3c);
      FUN_4501db37(&local_3c);
      uStackY_60 = 0x4501f6f7;
      _swprintf_s(local_14,5,L"%02ld%02ld");
    }
    sVar1 = _wcslen(local_14);
    if (sVar1 != 0) {
      do {
        if ((local_34 & 1 << ((byte)uVar4 & 0x1f)) != 0) {
          local_14[uVar4] = awStackY_8c[(ushort)local_14[uVar4]];
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < sVar1);
    }
    FUN_4501f984(param_1,local_14);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


