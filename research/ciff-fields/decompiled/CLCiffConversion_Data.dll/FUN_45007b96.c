// Source: CLCiffConversion_Data.dll @ 45007b96; FUN_45007b96

void __thiscall FUN_45007b96(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)this) && (param_3 == *(int **)this)) {
    FUN_45007aec(this);
    *param_1 = **(undefined4 **)this;
  }
  else {
    while (piVar1 = param_2, param_2 != param_3) {
      FUN_45005947((int *)&param_2);
      FUN_45007be5(this,&local_8,piVar1);
    }
    *param_1 = param_2;
  }
  return;
}


