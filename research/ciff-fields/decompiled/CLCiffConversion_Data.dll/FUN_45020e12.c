// Source: CLCiffConversion_Data.dll @ 45020e12; FUN_45020e12

_ATL_BASE_MODULE70 * __fastcall FUN_45020e12(_ATL_BASE_MODULE70 *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  ATL::_ATL_BASE_MODULE70::_ATL_BASE_MODULE70(param_1);
  *(undefined4 *)param_1 = 0x38;
  *(IMAGE_DOS_HEADER **)(param_1 + 8) = &IMAGE_DOS_HEADER_45000000;
  *(IMAGE_DOS_HEADER **)(param_1 + 4) = &IMAGE_DOS_HEADER_45000000;
  *(undefined4 *)(param_1 + 0xc) = 0xc00;
  *(undefined **)(param_1 + 0x10) = &DAT_450417a4;
  DVar1 = FUN_4500a222((LPCRITICAL_SECTION)(param_1 + 0x14));
  if ((int)DVar1 < 0) {
    BVar2 = IsDebuggerPresent();
    if (BVar2 != 0) {
      OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
    }
    DAT_45053891 = 1;
  }
  return param_1;
}


