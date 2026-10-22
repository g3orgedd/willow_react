// Source: CLCiffConversion_Data.dll @ 450090b9; FUN_450090b9

void __thiscall FUN_450090b9(void *this,undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  void *local_8;
  
  local_8 = this;
  if ((param_2 == (int *)**(int **)this) && (param_3 == *(int **)this)) {
    FUN_45009098(this);
    *param_1 = **(undefined4 **)this;
  }
  else {
    while (piVar1 = param_2, param_2 != param_3) {
      FUN_45005947((int *)&param_2);
      FUN_45009108(this,&local_8,piVar1);
    }
    *param_1 = param_2;
  }
  return;
}


