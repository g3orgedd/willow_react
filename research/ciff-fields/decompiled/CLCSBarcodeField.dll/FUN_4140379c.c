// Source: CLCSBarcodeField.dll @ 4140379c; FUN_4140379c

void __thiscall FUN_4140379c(void *this,int param_1,void *param_2)

{
  rsize_t rVar1;
  int iVar2;
  
  iVar2 = FUN_4140353a(this,param_1);
  if (iVar2 != 0) {
    rVar1 = param_1 * 2;
    FUN_41406a84(*(void **)this,rVar1 + 2,param_2,rVar1);
    *(int *)(*(int *)this + -8) = param_1;
    *(undefined2 *)(rVar1 + *(int *)this) = 0;
  }
  return;
}


