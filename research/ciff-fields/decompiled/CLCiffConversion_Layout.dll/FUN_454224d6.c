// Source: CLCiffConversion_Layout.dll @ 454224d6; FUN_454224d6

void __thiscall FUN_454224d6(void *this,int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  FID_conflict__free(param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  return;
}


