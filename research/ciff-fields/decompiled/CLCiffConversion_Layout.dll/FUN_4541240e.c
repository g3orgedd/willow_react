// Source: CLCiffConversion_Layout.dll @ 4541240e; FUN_4541240e

void __thiscall
FUN_4541240e(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 == (int *)**(int **)this) {
    FUN_4541228f(this,param_2,param_3,param_4);
    uVar2 = **(undefined4 **)this;
  }
  else {
    puVar1 = (undefined4 *)param_2[1];
    FUN_4541228f(this,param_2,param_3,param_4);
    uVar2 = *puVar1;
  }
  *param_1 = uVar2;
  return;
}


