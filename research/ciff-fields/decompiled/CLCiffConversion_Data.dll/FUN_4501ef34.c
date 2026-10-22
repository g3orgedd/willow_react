// Source: CLCiffConversion_Data.dll @ 4501ef34; FUN_4501ef34

undefined4 __fastcall FUN_4501ef34(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  double local_10;
  uint local_8;
  
  local_10 = *(double *)(param_1 + 0x2c);
  iVar2 = FUN_4501db37(&local_10);
  iVar3 = FUN_4501ddb8(&local_10);
  piVar1 = (int *)*param_1;
  uVar5 = 0;
  uVar6 = param_1[1] - (int)piVar1 >> 3;
  iVar3 = iVar2 * 100 + iVar3;
  if (uVar6 != 0) {
    local_8 = uVar6 - 1;
    piVar4 = piVar1;
    do {
      if ((uVar5 == local_8) || ((*piVar4 <= iVar3 && (iVar3 < piVar4[2])))) {
        FUN_4501f984(param_1,(wchar_t *)piVar1[uVar5 * 2 + 1]);
        return 0;
      }
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 2;
    } while (uVar5 < uVar6);
  }
  return 0;
}


