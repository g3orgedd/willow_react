// CiffMgr.dll entry=68117a9a

/* Library Function - Single Match
    public: virtual long __stdcall ATL::CComObjectNoLock<class
   ATL::CAccessibleProxy>::QueryInterface(struct _GUID const &,void * *)
   
   Library: Visual Studio 2012 Release */

long ATL::CComObjectNoLock<ATL::CAccessibleProxy>::QueryInterface(_GUID *param_1,void **param_2)

{
  long lVar1;
  void **in_stack_0000000c;
  
  lVar1 = AtlInternalQueryInterface
                    (param_1,(_ATL_INTMAP_ENTRY *)&PTR_DAT_6814b5b0,(_GUID *)param_2,
                     in_stack_0000000c);
  return lVar1;
}


