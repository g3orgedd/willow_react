// Source: CLCiffConversion_Layout.dll @ 454062e6; FUN_454062e6

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_454062e6(undefined4 *param_1)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  wchar_t *local_48;
  undefined1 local_44 [24];
  ushort local_2c [18];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x454062f2;
  local_48 = L"DontCare";
  uVar3 = 0;
  do {
    basic_string<>(local_2c,local_48);
    local_8 = 0;
    puVar1 = basic_string<>(local_44,(wchar_t *)*param_1);
    iVar2 = FUN_45406518(puVar1,local_2c);
    FUN_4540460c(local_44,'\x01',0);
    local_8 = 0xffffffff;
    FUN_4540460c(local_2c,'\x01',0);
    if (iVar2 == 0) break;
    uVar3 = uVar3 + 0x1c;
    local_48 = local_48 + 0xe;
  } while (uVar3 < 0xa8);
  FUN_4542a957();
  return;
}


