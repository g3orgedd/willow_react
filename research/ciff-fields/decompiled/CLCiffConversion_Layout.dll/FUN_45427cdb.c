// Source: CLCiffConversion_Layout.dll @ 45427cdb; FUN_45427cdb

int __fastcall FUN_45427cdb(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  return iVar1 + -1;
}


