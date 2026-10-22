// Source: CLCiffConversion_Data.dll @ 4500a78f; FUN_4500a78f

void __cdecl FUN_4500a78f(short *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  
  psVar3 = param_1 + 1;
  uVar4 = 0;
  uVar2 = (uint)((int)param_2 + (1 - (int)psVar3)) >> 1;
  if (param_2 < psVar3) {
    uVar2 = 0;
  }
  if (uVar2 != 0) {
    do {
      sVar1 = *psVar3;
      if (((sVar1 != 0x5b) && (sVar1 != 0x5d)) && (sVar1 != 0x3b)) {
        *param_1 = sVar1;
        param_1 = param_1 + 1;
      }
      psVar3 = psVar3 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 != uVar2);
  }
  return;
}


