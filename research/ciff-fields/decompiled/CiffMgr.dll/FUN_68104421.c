// Source: CiffMgr.dll @ 68104421; ATL::InlineIsEqualUnknown

/* Library Function - Single Match
    int __stdcall ATL::InlineIsEqualUnknown(struct _GUID const &)
   
   Library: Visual Studio 2012 Release */

int ATL::InlineIsEqualUnknown(_GUID *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((((param_1->Data1 == 0) &&
       (iVar1._0_2_ = param_1->Data2, iVar1._2_2_ = param_1->Data3, iVar1 == 0)) &&
      (*(int *)param_1->Data4 == 0xc0)) && (*(int *)(param_1->Data4 + 4) == 0x46000000)) {
    iVar2 = 1;
  }
  return iVar2;
}


