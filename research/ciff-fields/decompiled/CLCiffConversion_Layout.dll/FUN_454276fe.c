// Source: CLCiffConversion_Layout.dll @ 454276fe; FUN_454276fe

int FUN_454276fe(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar2 = iVar2 + -1;
  if (iVar2 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(1);
    }
  }
  else if (iVar2 == 1) {
    (**(code **)(*DAT_4545fba8 + 8))();
  }
  return iVar2;
}


