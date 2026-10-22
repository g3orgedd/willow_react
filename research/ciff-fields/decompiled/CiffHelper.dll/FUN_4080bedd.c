// Source: CiffHelper.dll @ 4080bedd; FUN_4080bedd

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT FUN_4080bedd(LPCSTR param_1)

{
  HRESULT HVar1;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  if (param_1 == (LPCSTR)0x0) {
    return 0;
  }
  local_18[0] = 0;
  local_8 = 1;
  FUN_4080be87(local_18,param_1);
  HVar1 = FUN_4080bf1a();
  return HVar1;
}


