// Source: CLCiffConversion_Layout.dll @ 4543fc20; FUN_4543fc20

int __cdecl FUN_4543fc20(FILE *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (FILE *)0x0) {
    iVar1 = flsall(0);
  }
  else {
    iVar1 = FUN_4543fc66(param_1);
    if (iVar1 == 0) {
      if ((param_1->_flag & 0x4000U) == 0) {
        iVar1 = 0;
      }
      else {
        uVar2 = __fileno(param_1);
        iVar1 = FUN_454408b5(uVar2);
        iVar1 = -(uint)(iVar1 != 0);
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


