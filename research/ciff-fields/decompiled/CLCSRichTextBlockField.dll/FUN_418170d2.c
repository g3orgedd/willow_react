// Source: CLCSRichTextBlockField.dll @ 418170d2; FUN_418170d2

void __thiscall FUN_418170d2(void *this,int param_1,float param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    if (*(int *)((int)this + 4) != 1) {
      return;
    }
    iVar1 = FUN_41818a99(this,param_2);
    *(undefined4 *)((int)this + 4) = 0;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    if (*(int *)((int)this + 4) != 0) {
      return;
    }
    iVar1 = FUN_41818734(this,param_2);
    *(undefined4 *)((int)this + 4) = 1;
  }
  *(int *)this = iVar1;
  return;
}


