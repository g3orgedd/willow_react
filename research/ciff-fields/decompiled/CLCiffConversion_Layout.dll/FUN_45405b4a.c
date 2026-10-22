// Source: CLCiffConversion_Layout.dll @ 45405b4a; FUN_45405b4a

int __thiscall FUN_45405b4a(void *this,rsize_t param_1,void *param_2,rsize_t param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + param_3;
  iVar2 = 1;
  if ((iVar1 < (int)param_1) || (iVar1 < (int)param_3)) {
    iVar2 = 0;
  }
  else if (iVar1 != 0) {
    iVar2 = FUN_45402e54(this,iVar1);
    if (iVar2 != 0) {
      FUN_45404b24(*(void **)this,iVar1 + 1,param_2,param_1);
      FUN_45404b24((void *)(*(int *)this + param_1),(iVar1 - param_1) + 1,param_4,param_3);
    }
  }
  return iVar2;
}


