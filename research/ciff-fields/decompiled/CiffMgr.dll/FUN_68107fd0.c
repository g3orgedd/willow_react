// Source: CiffMgr.dll @ 68107fd0; FUN_68107fd0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_68107fd0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ATL::
             CComObject<ATL::CComEnumOnSTL<IEnumVARIANT,&struct__GUID_const_IID_IEnumVARIANT,tagVARIANT,ATL::_Copy<tagVARIANT>,CCLVector<ATL::CComVariant>,ATL::CComSingleThreadModel>_>
             ::vftable;
  param_1[4] = 0xc0000001;
  (**(code **)(*DAT_6816703c + 8))();
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


