// Source: CLCiffConversion_Data.dll @ 450270fe; FUN_450270fe

UINT __cdecl FUN_450270fe(UINT param_1)

{
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_45021444(local_14,(int *)0x0);
  DAT_45055384 = 0;
  if (param_1 == 0xfffffffe) {
    DAT_45055384 = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == 0xfffffffd) {
    DAT_45055384 = 1;
    param_1 = GetACP();
  }
  else if (param_1 == 0xfffffffc) {
    DAT_45055384 = 1;
    param_1 = *(UINT *)(local_14[0] + 4);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return param_1;
}


