// Source: CLCiffConversion_Layout.dll @ 454243a1; FUN_454243a1

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_454243a1(void *this,CRegKey *param_1,char *param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  long lVar6;
  wchar_t *pwVar7;
  HRESULT HVar8;
  undefined4 *_Memory;
  uint uStack_114c;
  size_t sStack_1138;
  size_t sStack_1134;
  undefined4 *local_1130;
  CRegKey *local_112c;
  char *local_1128;
  undefined4 *local_1124;
  uint local_1120 [66];
  CHAR local_1018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_45446195;
  local_10 = ExceptionList;
  uStack_114c = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_114c;
  ExceptionList = &local_10;
  local_112c = param_1;
  local_1128 = param_2;
  local_1120[0] = 0;
  local_1130 = this;
  local_1124 = this;
  local_18 = uStack_114c;
  iVar3 = FUN_45426781(this,local_1018);
  if ((iVar3 < 0) || (iVar3 = FUN_454283af(local_1018,(undefined2 *)local_1120), iVar3 == 0))
  goto LAB_454247ed;
  FUN_45427bf6(local_1130);
  iVar3 = FUN_45426781(local_1130,local_1018);
  if (iVar3 < 0) goto LAB_454247ed;
  uVar4 = local_1120[0] & 0xffff;
  if (uVar4 == 8) {
    uVar4 = ATL::CRegKey::SetStringValue(param_1,param_2,local_1018,1);
LAB_454247c6:
    if (uVar4 != 0) {
      FUN_45424c03(uVar4);
      goto LAB_454247ed;
    }
  }
  else {
    if (uVar4 == 0x11) {
      sStack_1138 = _strlen(local_1018);
      if ((sStack_1138 & 1) == 0) {
        local_1120[1] = 0;
        sStack_1134 = (int)sStack_1138 / 2;
        local_8 = 5;
        Allocate(local_1120 + 1,sStack_1134);
        FUN_454246e4();
        return;
      }
      goto LAB_454247ed;
    }
    if (uVar4 == 0x13) {
      local_1124 = (undefined4 *)0x0;
      local_8 = 3;
      sVar5 = _strlen(local_1018);
      local_1120[0] = sVar5 + 1;
      lVar6 = ATL::AtlMultiply<int>((int *)local_1120,local_1120[0],2);
      uVar4 = local_1120[0];
      if (lVar6 < 0) goto LAB_454247ed;
      if (((int)local_1120[0] < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_1120[0]), bVar2)) {
        local_14 = (undefined1 *)&uStack_114c;
        pwVar7 = (wchar_t *)&uStack_114c;
        _Memory = (undefined4 *)0x0;
      }
      else {
        pwVar7 = (wchar_t *)FUN_454145c6(&local_1124,uVar4);
        _Memory = local_1124;
      }
      pwVar7 = AtlA2WHelper(pwVar7,local_1018,uVar4 >> 1,3);
      if (pwVar7 == (wchar_t *)0x0) {
        while (_Memory != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*_Memory;
          FID_conflict__free(_Memory);
          _Memory = puVar1;
        }
        goto LAB_454247ed;
      }
      HVar8 = VarUI4FromStr(pwVar7,0,0,&sStack_1134);
      if (HVar8 < 0) {
        while (_Memory != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*_Memory;
          FID_conflict__free(_Memory);
          _Memory = puVar1;
        }
        goto LAB_454247ed;
      }
      sStack_1138 = sStack_1134;
      uVar4 = RegSetValueExA(*(HKEY *)local_112c,local_1128,0,4,(BYTE *)&sStack_1138,4);
      while (_Memory != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)*_Memory;
        FID_conflict__free(_Memory);
        _Memory = puVar1;
      }
      goto LAB_454247c6;
    }
    if (uVar4 == 0x4008) {
      sVar5 = _strlen(local_1018);
      local_1120[1] = 0;
      local_8 = 1;
      Allocate(local_1120 + 1,sVar5 + 2);
      FUN_454244cd();
      return;
    }
  }
  FUN_45426781(local_1130,param_3);
LAB_454247ed:
  ExceptionList = local_10;
  FUN_4542a8d1(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


