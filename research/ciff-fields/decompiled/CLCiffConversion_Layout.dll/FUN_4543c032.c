// Source: CLCiffConversion_Layout.dll @ 4543c032; FID_conflict:_AtlDownlevelLocaleNameToLCID

/* Library Function - Multiple Matches With Different Base Names
    unsigned long __cdecl ATL::_AtlDownlevelLocaleNameToLCID(wchar_t const *)
    ___acrt_DownlevelLocaleNameToLCID
    ___crtDownlevelLocaleNameToLCID
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __cdecl FID_conflict__AtlDownlevelLocaleNameToLCID(wchar_t *param_1)

{
  uint uVar1;
  
  if (param_1 != (wchar_t *)0x0) {
    uVar1 = FID_conflict_GetTableIndexFromLocaleName(param_1);
    if ((-1 < (int)uVar1) && (uVar1 < 0xe4)) {
      return *(undefined4 *)(&DAT_45451e98 + uVar1 * 8);
    }
  }
  return 0;
}


