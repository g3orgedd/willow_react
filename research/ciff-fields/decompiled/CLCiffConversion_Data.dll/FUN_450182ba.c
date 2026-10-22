// Source: CLCiffConversion_Data.dll @ 450182ba; FUN_450182ba

bool FUN_450182ba(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
  uVar2 = param_2;
  if (uVar1 < param_2) {
    uVar2 = uVar1;
  }
  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar2 * 4;
  return param_2 != uVar2;
}


