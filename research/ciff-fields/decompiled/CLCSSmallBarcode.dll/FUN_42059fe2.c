// Source: CLCSSmallBarcode.dll @ 42059fe2; FUN_42059fe2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_42059fe2(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  BSTR pOVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  undefined4 **ppuVar16;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  int local_54;
  int local_50;
  BSTR local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  int local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x42059fee;
  local_38 = param_4;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCLCSSmallBarcodeObj::DoMicroPDF417Resize");
  local_8 = 0;
  FUN_420034ad(0x4209e120);
  (**(code **)(*(int *)*param_3 + 0x2c))();
  local_40 = (int)((double)(_DAT_42093e98 * 0.0) + _DAT_42093e80);
  (**(code **)(*(int *)*param_3 + 0x34))();
  iVar5 = param_1[3] - param_1[1];
  iVar2 = (int)((double)(_DAT_42093e98 * 0.0) + _DAT_42093e80);
  local_3c = param_1[2] - *param_1;
  (**(code **)(*(int *)*param_2 + 0x54))();
  iVar1 = local_40;
  iVar4 = local_3c;
  if (local_64 == 0) {
    iVar5 = (iVar5 * iVar2 + 5000) / 10000;
    iVar4 = (local_3c * local_40 + 5000) / 10000;
  }
  CComQIPtr<>(&local_30,(undefined4 *)*local_38);
  local_8._0_1_ = 1;
  if (local_30 != (int *)0x0) {
    local_68 = 0;
    (**(code **)(*local_30 + 0x18c))();
    local_60 = 0;
    (**(code **)(*local_30 + 0x194))();
    (**(code **)(*local_30 + 0x184))();
    local_40 = 0;
    (**(code **)(*local_30 + 0x174))();
    local_44 = 0;
    (**(code **)(*local_30 + 0x17c))();
    local_4c = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*local_30 + 0x98))();
    local_48 = 0;
    (**(code **)(*local_30 + 0x16c))();
    local_34 = 0;
    (**(code **)(*local_30 + 0x15c))();
    if (local_64 == 0) {
      local_34 = (local_34 * iVar1 + 5000) / 10000;
    }
    local_50 = 1;
    (**(code **)(*(int *)*local_38 + 0x108))();
    if (local_34 < 1) {
      local_34 = 1;
    }
    local_54 = 0;
    local_3c = 0;
    local_38 = (undefined4 *)0x0;
    ppuVar16 = &local_38;
    piVar15 = &local_3c;
    piVar14 = &local_54;
    uVar3 = (uint)(local_50 == 1);
    uVar7 = 1;
    pOVar6 = (BSTR)0x1;
    iVar13 = local_40;
    uVar9 = local_44;
    iVar10 = iVar2;
    uVar8 = local_68;
    uVar11 = local_60;
    iVar12 = local_48;
    FUN_42002e4a(&stack0xfffffef0,(int *)&local_4c);
    FUN_42059ea5(pOVar6,uVar7,uVar3,iVar13,uVar9,iVar10,uVar8,uVar11,iVar12,piVar14,piVar15,
                 (int *)ppuVar16);
    local_48 = 1;
    local_34 = iVar4 / (int)local_38;
    if (iVar4 / (int)local_38 < 1) {
      local_34 = 1;
    }
    ppuVar16 = &local_38;
    piVar15 = &local_3c;
    piVar14 = &local_54;
    iVar13 = 1;
    uVar3 = (uint)(local_50 == 1);
    uVar8 = 1;
    pOVar6 = (BSTR)0x1;
    iVar4 = local_40;
    uVar9 = local_44;
    FUN_42002e4a(&stack0xfffffef0,(int *)&local_4c);
    FUN_42059ea5(pOVar6,uVar8,uVar3,iVar4,uVar9,iVar2,local_68,local_60,iVar13,piVar14,piVar15,
                 (int *)ppuVar16);
    iVar4 = local_54;
    if (local_50 == 1) {
      iVar4 = local_54 + -2;
    }
    iVar4 = local_3c - iVar4 * local_48;
    local_48 = (iVar5 - iVar4 * local_34) / ((local_3c - iVar4) * local_34);
    if (local_48 < 1) {
      local_48 = 1;
    }
    if (10 < local_48) {
      local_48 = 10;
    }
    if (local_64 == 0) {
      local_34 = (iVar1 / 2 + local_34 * 10000) / iVar1;
    }
    (**(code **)(*local_30 + 0x170))();
    (**(code **)(*local_30 + 0x160))();
    SysFreeString(local_4c);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))();
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4206a64e();
  return;
}


