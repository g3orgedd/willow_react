// Source: CLCiffConversion_Data.dll @ 4502103b; FUN_4502103b

int __cdecl FUN_4502103b(int param_1)

{
  undefined *puVar1;
  int *piVar2;
  
  piVar2 = &DAT_45041880;
  puVar1 = PTR_s_permission_denied_45041884;
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


