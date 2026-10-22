// Source: CLCiffConversion_Layout.dll @ 45406719; ATL::CComTypeInfoHolder::stringdispid::`vector_deleting_destructor'

/* Library Function - Single Match
    public: void * __thiscall ATL::CComTypeInfoHolder::stringdispid::`vector deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2012 Release */

void * __thiscall
ATL::CComTypeInfoHolder::stringdispid::_vector_deleting_destructor_(stringdispid *this,uint param_1)

{
  stringdispid *_Memory;
  
  if ((param_1 & 2) == 0) {
    SysFreeString(*(BSTR *)this);
    _Memory = this;
    if ((param_1 & 1) != 0) {
      FID_conflict__free(this);
    }
  }
  else {
    _Memory = this + -4;
    _eh_vector_destructor_iterator_(this,0xc,*(int *)_Memory,FUN_45401c67);
    if ((param_1 & 1) != 0) {
      FID_conflict__free(_Memory);
    }
  }
  return _Memory;
}


