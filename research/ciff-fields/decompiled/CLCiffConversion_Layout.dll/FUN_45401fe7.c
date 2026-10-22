// Source: CLCiffConversion_Layout.dll @ 45401fe7; FUN_45401fe7

int FUN_45401fe7(HDC param_1,int param_2)

{
  int iVar1;
  
  iVar1 = SetTextCharacterExtra(param_1,param_2);
  if (iVar1 == -0x80000000) {
    iVar1 = 0;
  }
  return iVar1;
}


