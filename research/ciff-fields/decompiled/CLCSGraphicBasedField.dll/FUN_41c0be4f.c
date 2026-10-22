// Source: CLCSGraphicBasedField.dll @ 41c0be4f; FUN_41c0be4f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_41c0be4f(int *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined8 *_Memory;
  UINT UVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  HRESULT HVar7;
  code *pcVar8;
  char *pcVar9;
  undefined4 local_2f0;
  undefined4 uStack_2ec;
  undefined4 local_2e8;
  undefined4 uStack_2e4;
  VARIANTARG local_2e0;
  undefined4 local_2d0;
  undefined4 uStack_2cc;
  undefined4 local_2c8;
  undefined4 uStack_2c4;
  undefined4 local_2c0;
  undefined4 uStack_2bc;
  undefined4 local_2b8;
  undefined4 uStack_2b4;
  VARIANTARG local_2b0;
  undefined2 local_2a0 [4];
  SAFEARRAY *local_298;
  _union_2683 local_290;
  _union_2683 local_280;
  _union_2683 local_270;
  _union_2683 local_260;
  _union_2683 local_250;
  void *local_240;
  BSTR local_23c;
  int *local_238;
  _union_2683 local_234;
  int *local_224;
  uint local_220;
  undefined8 *local_21c;
  bool local_215;
  wchar_t local_214 [262];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2e0;
  local_240 = param_2;
  local_224 = (int *)0x0;
  local_8 = 0;
  FUN_41c0bcef(&local_224);
  UVar2 = SysStringLen((BSTR)*param_1);
  if ((UVar2 == 0) || (UVar2 = SysStringLen((BSTR)*param_1), 0x104 < UVar2)) {
    local_215 = false;
  }
  else {
    FUN_41c1c6ba((short *)*param_1,(short *)0x0,0,(short *)0x0,0,local_214,0x100,(short *)0x0,0);
    sVar3 = _wcslen(local_214);
    local_215 = sVar3 != 0;
  }
  if (local_224 == (int *)0x0) goto LAB_41c0c423;
  CComQIPtr<>(&local_238,local_224);
  local_8._0_1_ = 1;
  if (local_238 != (int *)0x0) {
    (**(code **)(*local_238 + 0x30))(local_238,param_4);
  }
  pcVar9 = (char *)local_224;
  (**(code **)(*local_224 + 0x28))(local_224,param_3);
  local_2d0 = CONCAT22(local_2d0._2_2_,3);
  local_2c8 = 0;
  local_2c0 = CONCAT22(local_2c0._2_2_,3);
  local_2b8 = 0;
  FUN_41c18d70((uint *)&local_280,0,0x10);
  VariantInit((VARIANTARG *)&local_280.n2);
  local_280.n2.vt = 0xb;
  local_280._8_2_ = 1;
  FUN_41c18d70((uint *)&local_270,0,0x10);
  VariantInit((VARIANTARG *)&local_270.n2);
  local_270.n2.vt = 0xb;
  local_270._8_4_ = (uint)(ushort)local_270._10_2_ << 0x10;
  FUN_41c18d70((uint *)&local_2e0,0,0x10);
  VariantInit(&local_2e0);
  FUN_41c18d70((uint *)&local_2b0,0,0x10);
  VariantInit(&local_2b0);
  local_8._0_1_ = 7;
  local_2a0[0] = 0;
  FUN_41c044fc(local_2a0,L"");
  FUN_41c18d70((uint *)&local_260,0,0x10);
  VariantInit((VARIANTARG *)&local_260.n2);
  FUN_41c18d70((uint *)&local_290,0,0x10);
  VariantInit((VARIANTARG *)&local_290.n2);
  FUN_41c18d70((uint *)&local_250,0,0x10);
  VariantInit((VARIANTARG *)&local_250.n2);
  local_234.n2.vt = 3;
  uVar1 = local_234.n2.vt;
  local_234.n2.vt = 3;
  if (local_215 == true) {
    local_234._8_4_ = 1;
    local_8._0_1_ = 0xc;
    FUN_41c0be26(&local_260,(VARIANTARG *)&local_234.n2);
    pcVar8 = VariantClear_exref;
    VariantClear((VARIANTARG *)&local_234.n2);
    local_234.n2.vt = 3;
    local_234._8_4_ = 1;
    local_8._0_1_ = 0xd;
    FUN_41c0be26(&local_290,(VARIANTARG *)&local_234.n2);
    local_8._0_1_ = 0xb;
    VariantClear((VARIANTARG *)&local_234.n2);
    local_234._0_4_ = (uint)local_234.n2.wReserved1 << 0x10;
    FUN_41c0a72a(&local_234,param_1);
    local_8 = CONCAT31(local_8._1_3_,0xe);
    FUN_41c0be26(&local_250,(VARIANTARG *)&local_234.n2);
    VariantClear((VARIANTARG *)&local_234.n2);
LAB_41c0c261:
    local_2f0 = CONCAT22(local_2f0._2_2_,3);
    local_2e8 = 1;
    local_234.n2.vt = 3;
    local_234._8_4_ = 2;
    local_8._0_1_ = 0x12;
    iVar6 = (**(code **)(*local_224 + 0x20))
                      (local_224,local_260._0_4_,local_260.decVal.Hi32,local_260._8_4_,
                       local_260._12_4_,local_290._0_4_,local_290.decVal.Hi32,local_290._8_4_,
                       local_290._12_4_,local_250._0_4_,local_250.decVal.Hi32,local_250._8_4_,
                       local_250._12_4_,local_234._0_4_,local_234.decVal.Hi32,2,local_234._12_4_,
                       local_2f0,uStack_2ec,1,uStack_2e4,local_2a0,local_2d0,uStack_2cc,local_2c8,
                       uStack_2c4,local_2c0,uStack_2bc,local_2b8,uStack_2b4,local_280._0_4_,
                       local_280.decVal.Hi32,local_280._8_4_,local_280._12_4_,local_270._0_4_,
                       local_270.decVal.Hi32,local_270._8_4_,local_270._12_4_,&local_2e0,&local_2b0)
    ;
    (*pcVar8)(&local_234);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    (*pcVar8)(&local_2f0);
    if (((iVar6 == 0) && (HVar7 = SafeArrayAccessData(local_298,&local_21c), -1 < HVar7)) &&
       (local_21c != (undefined8 *)0x0)) {
      FUN_41c12fb7(local_240,local_21c);
      SafeArrayUnaccessData(local_298);
    }
  }
  else {
    local_234._8_4_ = 2;
    local_8._0_1_ = 0xf;
    local_234.n2.vt = uVar1;
    FUN_41c0be26(&local_260,(VARIANTARG *)&local_234.n2);
    pcVar8 = VariantClear_exref;
    VariantClear((VARIANTARG *)&local_234.n2);
    local_234._8_4_ = 0;
    local_234.n2.vt = 3;
    local_8._0_1_ = 0x10;
    FUN_41c0be26(&local_290,(VARIANTARG *)&local_234.n2);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    VariantClear((VARIANTARG *)&local_234.n2);
    UVar2 = SysStringLen((BSTR)*param_1);
    if (UVar2 != 0) {
      UVar2 = SysStringLen((BSTR)*param_1);
      if (UVar2 < 10) {
        FUN_41c01b3c(0x41c31940);
      }
      UVar2 = SysStringLen((BSTR)*param_1);
      local_21c = (undefined8 *)FUN_41c17fe6(UVar2 - 9 >> 1);
      if (local_21c == (undefined8 *)0x0) {
        pcVar9 = "CCLCSGraphicBasedFieldObj::LoadImage - pBytes is NULL";
      }
      else {
        local_23c = (BSTR)*param_1;
        if (local_23c != (BSTR)0xffffffee) {
          local_220 = 0;
          UVar2 = SysStringLen(local_23c);
          if ((UVar2 - 9 & 0xfffffffe) != 0) {
            do {
              uVar4 = FUN_41c0a78d((uint)(ushort)local_23c[local_220 * 2 + 9]);
              uVar5 = FUN_41c0a78d((uint)(ushort)local_23c[local_220 * 2 + 10]);
              *(char *)(local_220 + (int)local_21c) = (char)uVar4 * '\x10' + (char)uVar5;
              local_220 = local_220 + 1;
              UVar2 = SysStringLen((BSTR)*param_1);
              pcVar8 = VariantClear_exref;
            } while (local_220 < UVar2 - 9 >> 1);
          }
          UVar2 = SysStringLen((BSTR)*param_1);
          _Memory = local_21c;
          local_250._8_4_ = FUN_41c0a897(0x11,(undefined8 *)(UVar2 - 9 >> 1),local_21c);
          local_250.n2.vt = 0x2011;
          FID_conflict__free(_Memory);
          goto LAB_41c0c261;
        }
        FID_conflict__free(local_21c);
        pcVar9 = "CCLCSGraphicBasedFieldObj::LoadImage - pwc is NULL";
      }
    }
    FUN_41c01b3c((int)pcVar9);
  }
  (*pcVar8)(&local_250);
  (*pcVar8)(&local_290);
  (*pcVar8)(&local_260);
  (*pcVar8)(local_2a0);
  (*pcVar8)(&local_2b0);
  (*pcVar8)(&local_2e0);
  (*pcVar8)(&local_270);
  (*pcVar8)(&local_280);
  (*pcVar8)(&local_2c0);
  (*pcVar8)(&local_2d0);
  local_8 = local_8 & 0xffffff00;
  if (local_238 != (int *)0x0) {
    (**(code **)(*local_238 + 8))(local_238);
  }
LAB_41c0c423:
  local_8 = 0xffffffff;
  if (local_224 != (int *)0x0) {
    (**(code **)(*local_224 + 8))(local_224);
  }
  FUN_41c1a062();
  return;
}


