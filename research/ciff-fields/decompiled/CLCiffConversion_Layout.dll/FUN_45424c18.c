// Source: CLCiffConversion_Layout.dll @ 45424c18; ATL::AtlInternalQueryInterface

/* Library Function - Single Match
    long __stdcall ATL::AtlInternalQueryInterface(void *,struct ATL::_ATL_INTMAP_ENTRY const
   *,struct _GUID const &,void * *)
   
   Library: Visual Studio 2012 Release */

long ATL::AtlInternalQueryInterface
               (void *param_1,_ATL_INTMAP_ENTRY *param_2,_GUID *param_3,void **param_4)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if ((param_1 == (void *)0x0) || (param_2 == (_ATL_INTMAP_ENTRY *)0x0)) {
    lVar2 = -0x7ff8ffa9;
  }
  else if (param_4 == (void **)0x0) {
    lVar2 = -0x7fffbffd;
  }
  else {
    iVar3 = InlineIsEqualUnknown(param_3);
    if (iVar3 == 0) {
      for (; pcVar1 = *(code **)(param_2 + 8), pcVar1 != (code *)0x0; param_2 = param_2 + 0xc) {
        iVar3 = *(int *)param_2;
        if (iVar3 == 0) {
LAB_45424c79:
          if (pcVar1 == (code *)0x1) goto LAB_45424c49;
          lVar2 = (*pcVar1)(param_1,param_3,param_4,*(int *)(param_2 + 4));
          if (lVar2 == 0) goto LAB_45424c57;
          if ((iVar3 != 0) && (lVar2 < 0)) goto LAB_45424ca7;
        }
        else {
          iVar4 = _InlineIsEqualGUID(*(int **)param_2,(int *)param_3);
          if (iVar4 != 0) goto LAB_45424c79;
        }
      }
      lVar2 = -0x7fffbffe;
LAB_45424ca7:
      *param_4 = (void *)0x0;
    }
    else {
LAB_45424c49:
      piVar5 = (int *)(*(int *)(param_2 + 4) + (int)param_1);
      (**(code **)(*piVar5 + 4))(piVar5);
      *param_4 = piVar5;
LAB_45424c57:
      lVar2 = 0;
    }
  }
  return lVar2;
}


