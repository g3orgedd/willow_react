// Source: CLCiffConversion_Data.dll @ 45026c15; FUN_45026c15

char * __fastcall FUN_45026c15(int param_1)

{
  char *pcVar1;
  
  pcVar1 = *(char **)(param_1 + 4);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = "Unknown exception";
  }
  return pcVar1;
}


