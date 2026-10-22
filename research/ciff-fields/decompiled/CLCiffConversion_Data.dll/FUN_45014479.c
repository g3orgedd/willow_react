// Source: CLCiffConversion_Data.dll @ 45014479; FUN_45014479

int FUN_45014479(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  
  *param_3 = 0;
  iVar2 = -0x7ff8fff2;
  piVar1 = (int *)FUN_45025ad0(0x28);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_4501467d(piVar1 + 1);
    *piVar1 = (int)ATL::CComObjectCached<ATL::CComClassFactory>::vftable;
  }
  if (piVar1 != (int *)0x0) {
    piVar1[9] = param_1;
    iVar2 = FUN_4501890c((int)(piVar1 + 1));
    if (-1 < iVar2) {
      iVar2 = 0;
    }
    if ((iVar2 == 0) && (iVar2 = (**(code **)*piVar1)(piVar1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    (**(code **)(*piVar1 + 0x14))(1);
  }
  return iVar2;
}


