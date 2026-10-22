// Source: CLCiffConversion_Layout.dll @ 4540a48a; FUN_4540a48a

undefined2 * __cdecl FUN_4540a48a(uint param_1,uint param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = (param_2 - param_1) + 1 >> 1;
  if (param_2 < param_1) {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    iVar2 = param_1 - (int)param_3;
    do {
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = *(undefined2 *)(iVar2 + (int)param_3);
      }
      param_3 = param_3 + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 != uVar1);
  }
  return param_3;
}


