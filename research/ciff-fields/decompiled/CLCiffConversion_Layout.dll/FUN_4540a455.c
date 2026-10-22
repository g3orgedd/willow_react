// Source: CLCiffConversion_Layout.dll @ 4540a455; FUN_4540a455

undefined1 * __cdecl FUN_4540a455(uint param_1,uint param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 - param_1;
  iVar3 = 0;
  if (param_2 < param_1) {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    iVar2 = param_1 - (int)param_3;
    do {
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = param_3[iVar2];
      }
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  return param_3;
}


