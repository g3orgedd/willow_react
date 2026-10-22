// Source: CLCSTextBasedField.dll @ 4243b71f; FUN_4243b71f

int FUN_4243b71f(HDC param_1,int param_2)

{
  int iVar1;
  
  iVar1 = SetTextCharacterExtra(param_1,param_2);
  if (iVar1 == -0x80000000) {
    iVar1 = 0;
  }
  return iVar1;
}


