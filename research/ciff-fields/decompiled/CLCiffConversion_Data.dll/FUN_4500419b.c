// Source: CLCiffConversion_Data.dll @ 4500419b; FUN_4500419b

int __fastcall FUN_4500419b(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 2;
  LOCK();
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((iVar2 + -1 == 0) && (param_1 != (int *)0x0)) {
    FUN_45004503(param_1);
    FID_conflict__free(param_1);
  }
  return iVar2 + -1;
}


