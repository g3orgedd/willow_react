// Source: CLCiffConversion_Layout.dll @ 454241ec; FUN_454241ec

int FUN_454241ec(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 4);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  if (iVar1 + 1 == 2) {
    (**(code **)(*DAT_4545fba8 + 4))();
  }
  return iVar1 + 1;
}


