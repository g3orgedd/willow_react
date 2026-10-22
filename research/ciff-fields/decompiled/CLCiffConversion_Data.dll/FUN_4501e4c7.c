// Source: CLCiffConversion_Data.dll @ 4501e4c7; FUN_4501e4c7

uint __thiscall FUN_4501e4c7(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  int local_18;
  double local_14;
  double local_c;
  
  FUN_4501df58(&local_1c,0,0,0,0,0,0);
  *param_2 = local_1c;
  param_2[1] = local_18;
  *(double *)(param_2 + 2) = local_14;
  if (param_1 - 1U < 0x1f) {
    local_c = *(double *)this;
    iVar1 = FUN_4501d4ad(&local_c);
    iVar2 = param_1;
    if (0x1c < param_1) {
      iVar2 = FUN_4501d5f2(&local_c);
      iVar2 = param_1 + -0x1f + iVar2;
    }
    if (iVar1 != iVar2) {
      if (iVar2 < iVar1) {
        if (0x1c < param_1) {
          local_14 = local_c;
          FUN_4501d29d(&local_14,1);
          iVar2 = FUN_4501d5f2(&local_14);
          iVar2 = param_1 + -0x1f + iVar2;
        }
        iVar3 = FUN_4501d5f2(&local_c);
        FUN_4501df58(&local_1c,0,0,iVar3 + (iVar2 - iVar1),0,0,0);
        *param_2 = local_1c;
        param_2[1] = local_18;
        iVar1 = local_18;
      }
      else {
        iVar1 = FUN_4501df58(&local_1c,0,0,iVar2 - iVar1,0,0,0);
        *param_2 = local_1c;
        param_2[1] = local_18;
      }
      *(double *)(param_2 + 2) = local_14;
    }
    uVar4 = CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  else {
    uVar4 = param_1 - 1U & 0xffffff00;
  }
  return uVar4;
}


