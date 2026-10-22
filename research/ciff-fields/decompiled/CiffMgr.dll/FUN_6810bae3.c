// Source: CiffMgr.dll @ 6810bae3; FUN_6810bae3

int FUN_6810bae3(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_3 = 0;
    iVar1 = -0x7ff8fff2;
    piVar2 = (int *)FUN_68132c9e(0x28);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      FUN_68103c5f(piVar2 + 1);
      *piVar2 = (int)ATL::CComObjectCached<ATL::CComClassFactory>::vftable;
    }
    if (piVar2 != (int *)0x0) {
      piVar2[9] = param_1;
      iVar1 = FUN_681046e7((int)(piVar2 + 1));
      if (-1 < iVar1) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) || (iVar1 = (**(code **)*piVar2)(piVar2,param_2,param_3), iVar1 != 0)) {
        (**(code **)(*piVar2 + 0x14))(1);
      }
    }
  }
  return iVar1;
}


