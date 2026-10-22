// Source: CLCiffConversion_Data.dll @ 45016a0e; FUN_45016a0e

undefined4 __thiscall FUN_45016a0e(void *this,LCID param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)((int)this + 0xc) == 0) {
    uVar2 = FUN_4501680f(this,param_1);
  }
  *param_2 = *(undefined4 *)((int)this + 0xc);
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}


