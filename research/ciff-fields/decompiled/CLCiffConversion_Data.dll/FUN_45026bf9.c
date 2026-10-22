// Source: CLCiffConversion_Data.dll @ 45026bf9; std::exception::_Tidy

/* Library Function - Single Match
    private: void __thiscall std::exception::_Tidy(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall std::exception::_Tidy(exception *this)

{
  if (this[8] != (exception)0x0) {
    FID_conflict__free(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  this[8] = (exception)0x0;
  return;
}


