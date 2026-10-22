// Source: CLCSTextBasedField.dll @ 42403f2b; FUN_42403f2b

void __thiscall FUN_42403f2b(void *this,int param_1,void *param_2)

{
  rsize_t rVar1;
  int iVar2;
  
  iVar2 = FUN_42403cc9(this,param_1);
  if (iVar2 != 0) {
    rVar1 = param_1 * 2;
    FUN_42406d75(*(void **)this,rVar1 + 2,param_2,rVar1);
    *(int *)(*(int *)this + -8) = param_1;
    *(undefined2 *)(rVar1 + *(int *)this) = 0;
  }
  return;
}


