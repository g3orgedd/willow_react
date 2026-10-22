// Source: CLCiffConversion_Layout.dll @ 454264d7; FUN_454264d7

undefined4 FUN_454264d7(char param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < '\t') || ((('\n' < param_1 && (param_1 != '\r')) && (param_1 != ' ')))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


