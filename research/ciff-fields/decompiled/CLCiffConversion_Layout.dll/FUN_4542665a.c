// Source: CLCiffConversion_Layout.dll @ 4542665a; FUN_4542665a

int __fastcall FUN_4542665a(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 8);
  LOCK();
  iVar1 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  return iVar1 + 1;
}


