// Source: CLCiffConversion_Layout.dll @ 45404652; FUN_45404652

void __thiscall FUN_45404652(void *this,int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  FUN_45402c5d(param_1 + 2);
  FID_conflict__free(param_1);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  return;
}


