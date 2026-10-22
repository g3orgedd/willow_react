// Source: CLCiffConversion_Layout.dll @ 45402eec; ATL::CTempBuffer<wchar_t,128,ATL::CCRTAllocator>::Allocate

/* Library Function - Single Match
    public: wchar_t * __thiscall ATL::CTempBuffer<wchar_t,128,class
   ATL::CCRTAllocator>::Allocate(unsigned int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

wchar_t * __thiscall
ATL::CTempBuffer<wchar_t,128,ATL::CCRTAllocator>::Allocate
          (CTempBuffer<wchar_t,128,ATL::CCRTAllocator> *this,uint param_1)

{
  ulong uVar1;
  
  uVar1 = FUN_454024b0(param_1,2);
  if (uVar1 < 0x81) {
    *(CTempBuffer<wchar_t,128,ATL::CCRTAllocator> **)this = this + 4;
  }
  else {
    FUN_45402f1b(this,uVar1);
  }
  return *(wchar_t **)this;
}


