// Source: CiffMgr.dll @ 6810c13f; FUN_6810c13f

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_6810c13f(void *this,CRegKey *param_1,wchar_t *param_2,undefined2 *param_3)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  HRESULT HVar4;
  uint uStack_214c;
  size_t sStack_212c;
  size_t sStack_2128;
  undefined4 *local_2124;
  uint local_2120 [66];
  WCHAR local_2018 [4096];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_681432c2;
  local_10 = ExceptionList;
  uStack_214c = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_214c;
  ExceptionList = &local_10;
  local_2120[0] = 0;
  local_2124 = this;
  local_18 = uStack_214c;
  iVar1 = FUN_6810d73a(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_6810ef1d(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_6810c4b5;
  FUN_6810e9ac(local_2124);
  iVar1 = FUN_6810d73a(local_2124,local_2018);
  if (iVar1 < 0) goto LAB_6810c4b5;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 == 8) {
    uVar2 = ATL::CRegKey::SetStringValue(param_1,param_2,local_2018,1);
LAB_6810c48c:
    if (uVar2 != 0) {
      FUN_6810c93a(uVar2);
      goto LAB_6810c4b5;
    }
  }
  else {
    if (uVar2 == 0x11) {
      sStack_2128 = _wcslen(local_2018);
      if ((sStack_2128 & 1) == 0) {
        local_2120[1] = 0;
        sStack_212c = (int)sStack_2128 / 2;
        local_8 = 4;
        Allocate(local_2120 + 1,sStack_212c);
        FUN_6810c3ac();
        return;
      }
      goto LAB_6810c4b5;
    }
    if (uVar2 == 0x13) {
      HVar4 = VarUI4FromStr(local_2018,0,0,&sStack_212c);
      if (HVar4 < 0) goto LAB_6810c4b5;
      sStack_2128 = sStack_212c;
      uVar2 = RegSetValueExW(*(HKEY *)param_1,param_2,0,4,(BYTE *)&sStack_2128,4);
      goto LAB_6810c48c;
    }
    if (uVar2 == 0x4008) {
      sVar3 = _wcslen(local_2018);
      local_2120[1] = 0;
      local_8 = 1;
      Allocate(local_2120 + 1,sVar3 + 2);
      FUN_6810c26b();
      return;
    }
  }
  FUN_6810d73a(local_2124,param_3);
LAB_6810c4b5:
  ExceptionList = local_10;
  FUN_68132051(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


