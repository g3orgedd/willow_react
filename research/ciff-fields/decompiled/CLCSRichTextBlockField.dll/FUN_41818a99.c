// Source: CLCSRichTextBlockField.dll @ 41818a99; FUN_41818a99

int __thiscall FUN_41818a99(void *this,float param_1)

{
  int iVar1;
  
  if (*(int *)((int)this + 4) == 0) {
    iVar1 = *(int *)this;
  }
  else if (*(int *)((int)this + 4) == 1) {
    iVar1 = FUN_41802407((float)*(int *)this / param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


