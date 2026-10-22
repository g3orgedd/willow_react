// Source: CLCiffConversion_Data.dll @ 45002400; _com_error::`scalar_deleting_destructor'

/* Library Function - Single Match
    public: virtual void * __thiscall _com_error::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

void * __thiscall _com_error::_scalar_deleting_destructor_(_com_error *this,uint param_1)

{
  ~_com_error(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


