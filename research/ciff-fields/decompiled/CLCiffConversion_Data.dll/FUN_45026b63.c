// Source: CLCiffConversion_Data.dll @ 45026b63; std::exception::operator=

/* Library Function - Single Match
    public: class std::exception & __thiscall std::exception::operator=(class std::exception const
   &)
   
   Library: Visual Studio 2012 Release */

exception * __thiscall std::exception::operator=(exception *this,exception *param_1)

{
  if (this != param_1) {
    _Tidy(this);
    if (param_1[8] == (exception)0x0) {
      *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
    }
    else {
      FUN_45026bbb(this,*(char **)(param_1 + 4));
    }
  }
  return this;
}


