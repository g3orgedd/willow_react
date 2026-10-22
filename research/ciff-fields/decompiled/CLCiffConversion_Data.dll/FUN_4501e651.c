// Source: CLCiffConversion_Data.dll @ 4501e651; FUN_4501e651

uint __thiscall FUN_4501e651(void *this,int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_2c;
  int local_28;
  undefined8 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  double local_14;
  double local_c;
  
  FUN_4501df58(&local_1c,0,0,0,0,0,0);
  *param_2 = local_1c;
  param_2[1] = local_18;
  *(double *)(param_2 + 2) = local_14;
  if (param_1 - 1U < 0x1f) {
    local_c = *(double *)this;
    iVar1 = FUN_4501d4ad(&local_c);
    iVar3 = param_1;
    if (0x1c < param_1) {
      iVar3 = FUN_4501d5f2(&local_c);
      iVar3 = iVar3 + -0x1f + param_1;
    }
    if (iVar1 != iVar3) {
      if (iVar1 < iVar3) {
        local_14 = local_c;
        FUN_4501d29d(&local_14,-1);
        if (param_1 < 0x1d) {
          iVar3 = FUN_4501d5f2(&local_14);
          iVar3 = iVar3 + (iVar1 - param_1);
        }
        else {
          iVar3 = (iVar1 - param_1) + 0x1f;
        }
      }
      else {
        iVar3 = iVar1 - iVar3;
      }
      FUN_4501df58(&local_2c,0,0,iVar3,0,0,0);
      *param_2 = local_2c;
      param_2[1] = local_28;
      *(undefined8 *)(param_2 + 2) = local_24;
      iVar3 = local_28;
    }
    uVar2 = CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  else {
    uVar2 = param_1 - 1U & 0xffffff00;
  }
  return uVar2;
}


