// Source: CLCiffConversion_Layout.dll @ 45426b09; FUN_45426b09

long FUN_45426b09(int *param_1,_GUID *param_2,void **param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_3 == (void **)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    lVar1 = 0;
    *param_3 = (void *)0x0;
    iVar2 = ATL::InlineIsEqualUnknown(param_2);
    if (iVar2 == 0) {
      lVar1 = ATL::AtlInternalQueryInterface
                        (param_1 + 4,(_ATL_INTMAP_ENTRY *)&PTR_DAT_4544ab68,param_2,param_3);
    }
    else {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return lVar1;
}


