// Source: CLCSBlockTextField.dll @ 418125b3; FUN_418125b3

int __thiscall FUN_418125b3(void *this,float param_1)

{
  int iVar1;
  
  if (*(int *)((int)this + 4) == 0) {
    iVar1 = *(int *)this;
  }
  else if (*(int *)((int)this + 4) == 1) {
    iVar1 = FUN_4181270a((float)*(int *)this / param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


