// Source: CLCiffConversion_Layout.dll @ 45402f40; FUN_45402f40

void __thiscall FUN_45402f40(void *this,rsize_t param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_45402e26(this,param_1);
  if (iVar1 != 0) {
    FUN_45404b24(*(void **)this,param_1 + 1,param_2,param_1);
    *(rsize_t *)(*(int *)this + -8) = param_1;
    *(undefined1 *)(param_1 + *(int *)this) = 0;
  }
  return;
}


