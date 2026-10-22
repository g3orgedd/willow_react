// Source: CLCiffConversion_Data.dll @ 45017fff; FUN_45017fff

int FUN_45017fff(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    (**(code **)(*DAT_45053870 + 4))();
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0xc))(1);
    }
    (**(code **)(*DAT_45053870 + 8))();
  }
  return iVar2 + -1;
}


