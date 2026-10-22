// Source: CLCiffConversion_Data.dll @ 450021f2; FUN_450021f2

undefined4 * __thiscall FUN_450021f2(void *this,int param_1)

{
  int *piVar1;
  
  *(undefined ***)this = _com_error::vftable;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(int **)((int)this + 8) = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return this;
}


