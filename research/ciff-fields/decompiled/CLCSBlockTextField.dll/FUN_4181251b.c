// Source: CLCSBlockTextField.dll @ 4181251b; FUN_4181251b

int __thiscall FUN_4181251b(void *this,float param_1)

{
  int iVar1;
  
  if (*(int *)((int)this + 4) == 0) {
    iVar1 = FUN_4181270a((float)*(int *)this * param_1);
  }
  else if (*(int *)((int)this + 4) == 1) {
    iVar1 = *(int *)this;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


