// Source: CLCiffConversion_Layout.dll @ 4542f263; std::exception::exception

/* Library Function - Single Match
    public: __thiscall std::exception::exception(char const * const &)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

exception * __thiscall std::exception::exception(exception *this,char **param_1)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined ***)this = vftable;
  this[8] = (exception)0x0;
  FUN_4542f329(this,*param_1);
  return this;
}


