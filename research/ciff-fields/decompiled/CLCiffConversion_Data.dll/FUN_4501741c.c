// Source: CLCiffConversion_Data.dll @ 4501741c; FUN_4501741c

int FUN_4501741c(int *param_1,_GUID *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_3 = 0;
  iVar1 = ATL::InlineIsEqualUnknown(param_2);
  if (iVar1 == 0) {
    iVar2 = FUN_45015610((int)(param_1 + 4),(int *)&PTR_DAT_4503fed0,param_2,param_3);
  }
  else {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
  }
  return iVar2;
}


