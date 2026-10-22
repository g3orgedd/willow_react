// Source: CLCiffConversion_Data.dll @ 45009c84; ATL::CAtlComModule::CAtlComModule

/* Library Function - Single Match
    public: __thiscall ATL::CAtlComModule::CAtlComModule(void)
   
   Library: Visual Studio 2015 Release */

CAtlComModule * __thiscall ATL::CAtlComModule::CAtlComModule(CAtlComModule *this)

{
  DWORD DVar1;
  
  _ATL_COM_MODULE70::_ATL_COM_MODULE70((_ATL_COM_MODULE70 *)this);
  *(undefined4 *)this = 0;
  *(IMAGE_DOS_HEADER **)(this + 4) = &IMAGE_DOS_HEADER_45000000;
  *(undefined **)(this + 8) = &DAT_4504ff60;
  *(undefined **)(this + 0xc) = &DAT_4504ff60;
  DVar1 = FUN_4500a222((LPCRITICAL_SECTION)(this + 0x10));
  if ((int)DVar1 < 0) {
    DAT_45053891 = 1;
  }
  else {
    *(undefined4 *)this = 0x28;
  }
  return this;
}


