// Source: CLCiffConversion_Data.dll @ 4500352a; FUN_4500352a

int __thiscall FUN_4500352a(void *this,int param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = param_1 + param_3;
  if ((iVar1 < param_1) || (iVar1 < param_3)) {
    iVar2 = 0;
  }
  else if (iVar1 != 0) {
    iVar2 = FUN_4500244d(this,iVar1);
    if (iVar2 != 0) {
      FUN_45004ebd(*(void **)this,iVar1 * 2 + 2,param_2,param_1 * 2);
      FUN_45004ebd((void *)(*(int *)this + param_1 * 2),(iVar1 - param_1) * 2 + 2,param_4,
                   param_3 * 2);
    }
  }
  return iVar2;
}


