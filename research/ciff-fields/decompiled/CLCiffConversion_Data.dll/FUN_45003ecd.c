// Source: CLCiffConversion_Data.dll @ 45003ecd; FUN_45003ecd

void __fastcall FUN_45003ecd(LPCWSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int local_14;
  int local_10;
  int local_8;
  
  iVar1 = FUN_45003392();
  *(int *)(param_1 + 2) = iVar1;
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_45003437(&local_8);
    iVar1 = _wcscmp((wchar_t *)*puVar2,L"notpresent");
    FUN_45002256(&local_8);
    if (iVar1 == 0) {
      FUN_450032f6(&stack0xffffffe0);
      FUN_45001fdf(&local_14);
      local_10 = local_14 * 0x3c + local_10;
      if (local_14 < 0xc) {
        iVar1 = local_10 * -0x3c;
        if (local_10 * 0x3c != -0x1517f && 0x1517e < iVar1) {
          iVar1 = 0x1517f;
        }
        if (iVar1 < -0x1517f) {
          iVar1 = -0x1517f;
        }
        *(int *)param_1 = iVar1;
      }
      else {
        iVar1 = local_10 * -0x3c + 0x15180;
        if (0x1517f < iVar1) {
          iVar1 = 0x1517f;
        }
        if (iVar1 < -0x1517f) {
          iVar1 = -0x1517f;
        }
        *(int *)param_1 = iVar1;
      }
      FUN_45004245(param_1);
    }
    else {
      iVar1 = extraout_ECX;
      FUN_45003437(&stack0xffffffe0);
      FUN_45004c52(param_1,iVar1);
    }
  }
  return;
}


