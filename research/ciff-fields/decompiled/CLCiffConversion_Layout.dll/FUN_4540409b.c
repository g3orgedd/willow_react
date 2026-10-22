// Source: CLCiffConversion_Layout.dll @ 4540409b; FUN_4540409b

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4540409b(undefined4 *param_1)

{
  UINT UVar1;
  ulong uVar2;
  undefined4 local_9c [37];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x11c;
  local_8 = 0x454040aa;
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 != 0) {
    UVar1 = SysStringLen((BSTR)*param_1);
    uVar2 = WideCharToMultiByte(3,0,(LPCWSTR)*param_1,UVar1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    local_9c[0] = 0;
    local_8 = 1;
    Allocate(local_9c,uVar2);
    FUN_4540410f();
    return;
  }
  FUN_4542a966();
  return;
}


