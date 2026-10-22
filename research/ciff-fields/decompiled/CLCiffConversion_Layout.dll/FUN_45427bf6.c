// Source: CLCiffConversion_Layout.dll @ 45427bf6; FUN_45427bf6

void __fastcall FUN_45427bf6(undefined4 *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)*param_1;
  while( true ) {
    iVar2 = FUN_454264d7(*pcVar1);
    if (iVar2 == 0) break;
    pcVar1 = CharNextA((LPCSTR)*param_1);
    *param_1 = pcVar1;
  }
  return;
}


