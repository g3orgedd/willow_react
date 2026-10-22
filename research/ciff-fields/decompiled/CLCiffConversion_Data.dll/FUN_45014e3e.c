// Source: CLCiffConversion_Data.dll @ 45014e3e; FUN_45014e3e

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_45014e3e(void *this,undefined4 *param_1,LPCWSTR param_2,undefined2 *param_3)

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
  puStack_c = &LAB_4503b84c;
  local_10 = ExceptionList;
  uStack_214c = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_214c;
  ExceptionList = &local_10;
  local_2120[0] = 0;
  local_2124 = this;
  local_18 = uStack_214c;
  iVar1 = FUN_4501703e(this,local_2018);
  if ((iVar1 < 0) || (iVar1 = FUN_45018875(local_2018,(undefined2 *)local_2120), iVar1 == 0))
  goto LAB_450151b4;
  FUN_4501834e(local_2124);
  iVar1 = FUN_4501703e(local_2124,local_2018);
  if (iVar1 < 0) goto LAB_450151b4;
  uVar2 = local_2120[0] & 0xffff;
  if (uVar2 == 8) {
    uVar2 = FUN_4501828b(param_1,param_2,local_2018,1);
LAB_4501518b:
    if (uVar2 != 0) {
      FUN_450155fb(uVar2);
      goto LAB_450151b4;
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
        FUN_450150ab();
        return;
      }
      goto LAB_450151b4;
    }
    if (uVar2 == 0x13) {
      HVar4 = VarUI4FromStr(local_2018,0,0,&sStack_212c);
      if (HVar4 < 0) goto LAB_450151b4;
      sStack_2128 = sStack_212c;
      uVar2 = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)&sStack_2128,4);
      goto LAB_4501518b;
    }
    if (uVar2 == 0x4008) {
      sVar3 = _wcslen(local_2018);
      local_2120[1] = 0;
      local_8 = 1;
      Allocate(local_2120 + 1,sVar3 + 2);
      FUN_45014f6a();
      return;
    }
  }
  FUN_4501703e(local_2124,param_3);
LAB_450151b4:
  ExceptionList = local_10;
  FUN_45022e32(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


