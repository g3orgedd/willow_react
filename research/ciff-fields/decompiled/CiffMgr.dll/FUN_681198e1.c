// Source: CiffMgr.dll @ 681198e1; CComQIPtr<>

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall ATL::CComQIPtr<struct IChapteredRowset,&struct __s_GUID const
   _GUID_0c733a93_2a1c_11ce_ade5_00aa0044773d>::CComQIPtr<struct IChapteredRowset,&struct __s_GUID
   const _GUID_0c733a93_2a1c_11ce_ade5_00aa0044773d>(struct IUnknown *)
    public: __thiscall ATL::CComQIPtr<struct IHTMLDocument2,&struct __s_GUID const
   _GUID_332c4425_26cb_11d0_b483_00c04fd90119>::CComQIPtr<struct IHTMLDocument2,&struct __s_GUID
   const _GUID_332c4425_26cb_11d0_b483_00c04fd90119>(struct IUnknown *)
    public: __thiscall ATL::CComQIPtr<struct IOleCommandTarget,&struct __s_GUID const
   _GUID_b722bccb_4e68_101b_a2bc_00aa00404770>::CComQIPtr<struct IOleCommandTarget,&struct __s_GUID
   const _GUID_b722bccb_4e68_101b_a2bc_00aa00404770>(struct IUnknown *)
    public: __thiscall ATL::CComQIPtr<struct IOleInPlaceActiveObject,&struct __s_GUID const
   _GUID_00000117_0000_0000_c000_000000000046>::CComQIPtr<struct IOleInPlaceActiveObject,&struct
   __s_GUID const _GUID_00000117_0000_0000_c000_000000000046>(struct IUnknown *)
     13 names - too many to list
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2019 Release */

undefined4 * __thiscall CComQIPtr<>(void *this,undefined4 *param_1)

{
  int iVar1;
  
  *(undefined4 *)this = 0;
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = (**(code **)*param_1)(param_1,&DAT_68147e58,this);
    if (iVar1 < 0) {
      *(undefined4 *)this = 0;
    }
  }
  return this;
}


