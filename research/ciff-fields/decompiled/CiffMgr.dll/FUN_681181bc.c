// Source: CiffMgr.dll @ 681181bc; ATL::CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>::operator=

/* Library Function - Single Match
    public: struct IPersistStreamInit * __thiscall ATL::CComQIPtr<struct IPersistStreamInit,&struct
   __s_GUID const _GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>::operator=(struct IUnknown *)
   
   Library: Visual Studio 2012 Release */

IPersistStreamInit * __thiscall
ATL::CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
::operator=(CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
            *this,IUnknown *param_1)

{
  IPersistStreamInit *pIVar1;
  
  if (*(IUnknown **)this == param_1) {
    pIVar1 = *(IPersistStreamInit **)this;
  }
  else {
    pIVar1 = (IPersistStreamInit *)
             AtlComQIPtrAssign((IUnknown **)this,param_1,(_GUID *)&DAT_681482a0);
  }
  return pIVar1;
}


