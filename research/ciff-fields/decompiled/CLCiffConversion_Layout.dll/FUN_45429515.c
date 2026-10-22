// Source: CLCiffConversion_Layout.dll @ 45429515; FUN_45429515

int __cdecl FUN_45429515(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  
  piVar2 = &DAT_4544b1b0;
  puVar1 = PTR_s_permission_denied_4544b1b4;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return 0;
    }
    if (*piVar2 == param_1) break;
    puVar1 = (undefined *)piVar2[3];
    piVar2 = piVar2 + 2;
  }
  return piVar2[1];
}


