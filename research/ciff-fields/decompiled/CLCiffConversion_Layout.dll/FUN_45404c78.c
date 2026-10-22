// Source: CLCiffConversion_Layout.dll @ 45404c78; FUN_45404c78

undefined4 * __thiscall FUN_45404c78(void *this,int param_1)

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


