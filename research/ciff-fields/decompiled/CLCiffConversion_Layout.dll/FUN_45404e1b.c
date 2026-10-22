// Source: CLCiffConversion_Layout.dll @ 45404e1b; FUN_45404e1b

undefined4 __thiscall
FUN_45404e1b(void *this,undefined4 *param_1,rsize_t param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_4 + param_2;
  if (iVar2 == 0) {
    *param_1 = PTR_DAT_4545d110;
  }
  else {
    if (iVar2 < (int)param_2) {
      return 0;
    }
    iVar1 = FUN_45402e54(param_1,iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    FUN_45404b24((void *)*param_1,iVar2 + 1,(void *)(*(int *)this + param_3),param_2);
  }
  return 1;
}


