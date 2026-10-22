// Source: CLCiffConversion_Layout.dll @ 4543b768; FUN_4543b768

uint __cdecl FUN_4543b768(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2;
  do {
    if (*(int *)(uVar1 + 4) == param_1) break;
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < DAT_45450eb0 * 0xc + param_2);
  if ((DAT_45450eb0 * 0xc + param_2 <= uVar1) || (*(int *)(uVar1 + 4) != param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}


