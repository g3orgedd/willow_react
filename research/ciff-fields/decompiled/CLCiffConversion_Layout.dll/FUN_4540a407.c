// Source: CLCiffConversion_Layout.dll @ 4540a407; FUN_4540a407

void __cdecl FUN_4540a407(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (param_1 != (undefined4 *)0x0) {
      puVar2 = param_1;
      for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
    }
    param_1 = param_1 + 8;
  }
  return;
}


