// Source: CLCiffConversion_Data.dll @ 450361f9; FUN_450361f9

int __cdecl FUN_450361f9(FILE *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (FILE *)0x0) {
    iVar1 = flsall(0);
  }
  else {
    iVar1 = FUN_4503623f(param_1);
    if (iVar1 == 0) {
      if ((param_1->_flag & 0x4000U) == 0) {
        iVar1 = 0;
      }
      else {
        uVar2 = __fileno(param_1);
        iVar1 = FUN_45037cea(uVar2);
        iVar1 = -(uint)(iVar1 != 0);
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


