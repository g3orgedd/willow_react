// Source: CLCiffConversion_Data.dll @ 45021090; _com_issue_errorex

/* Library Function - Single Match
    void __stdcall _com_issue_errorex(long,struct IUnknown *,struct _GUID const &)
   
   Library: Visual Studio 2012 Release */

void _com_issue_errorex(long param_1,IUnknown *param_2,_GUID *param_3)

{
  HRESULT HVar1;
  void **unaff_ESI;
  
  if ((param_2 != (IUnknown *)0x0) &&
     (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,(IID *)&DAT_4503fdbc,&param_2), -1 < HVar1)
     ) {
    HVar1 = (*param_2->lpVtbl[1].QueryInterface)(param_2,param_3,unaff_ESI);
    (*param_2->lpVtbl->Release)(param_2);
    if (HVar1 == 0) {
      GetErrorInfo(0,(IErrorInfo **)&stack0xfffffff8);
      (*(code *)PTR_FUN_450518b4)(param_1);
      return;
    }
  }
  (*(code *)PTR_FUN_450518b4)(param_1);
  return;
}


