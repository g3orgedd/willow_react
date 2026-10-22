// Source: CLCiffConversion_Layout.dll @ 45423487; FUN_45423487

void __thiscall FUN_45423487(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)this) && (param_3 == *(int **)this)) {
    FUN_45409c9b(this);
    *param_1 = **(undefined4 **)this;
  }
  else {
    while (piVar1 = param_2, param_2 != param_3) {
      FUN_45409a25((int *)&param_2);
      FUN_454234d6(this,&local_8,piVar1);
    }
    *param_1 = param_2;
  }
  return;
}


