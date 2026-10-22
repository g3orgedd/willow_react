// Source: CLCiffConversion_Layout.dll @ 4543b281; FUN_4543b281

void __cdecl FUN_4543b281(uint *param_1,uint *param_2)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  
  uVar4 = 0x80000000;
  uVar1 = *param_2;
  uVar6 = *(ushort *)((int)param_2 + 6) & 0x8000;
  uVar2 = *(ushort *)((int)param_2 + 6) >> 4;
  uVar3 = uVar2 & 0x7ff;
  if ((uVar2 & 0x7ff) == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar1 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      *(ushort *)(param_1 + 2) = uVar6;
      return;
    }
    uVar3 = uVar3 + 0x3c01;
    uVar4 = 0;
  }
  else if (uVar3 == 0x7ff) {
    uVar3 = 0x7fff;
  }
  else {
    uVar3 = uVar3 + 0x3c00;
  }
  uVar5 = uVar1 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | uVar4;
  param_1[1] = uVar5;
  *param_1 = uVar1 << 0xb;
  if (uVar4 == 0) {
    do {
      uVar3 = uVar3 - 1;
      uVar5 = uVar5 * 2 | *param_1 >> 0x1f;
      *param_1 = *param_1 * 2;
    } while (-1 < (int)uVar5);
    param_1[1] = uVar5;
  }
  *(ushort *)(param_1 + 2) = uVar6 | uVar3;
  return;
}


