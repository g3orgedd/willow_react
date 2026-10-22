// Source: CLCiffConversion_Data.dll @ 4500a1dd; ATL::CW2WEX<128>::Init

/* Library Function - Single Match
    private: void __thiscall ATL::CW2WEX<128>::Init(wchar_t const *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall ATL::CW2WEX<128>::Init(CW2WEX<128> *this,wchar_t *param_1)

{
  rsize_t rVar1;
  size_t sVar2;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    sVar2 = _wcslen(param_1);
    FUN_45009bfc((int *)this,sVar2 + 1,(int)(this + 4),0x80);
    rVar1 = (sVar2 + 1) * 2;
    FUN_45004ebd(*(void **)this,rVar1,param_1,rVar1);
  }
  return;
}


