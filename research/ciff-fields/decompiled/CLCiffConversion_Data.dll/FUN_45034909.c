// Source: CLCiffConversion_Data.dll @ 45034909; FUN_45034909

uint __cdecl FUN_45034909(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2;
  do {
    if (*(int *)(uVar1 + 4) == param_1) break;
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < DAT_45047588 * 0xc + param_2);
  if ((DAT_45047588 * 0xc + param_2 <= uVar1) || (*(int *)(uVar1 + 4) != param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}


