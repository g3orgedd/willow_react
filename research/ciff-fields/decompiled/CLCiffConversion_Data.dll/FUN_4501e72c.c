// Source: CLCiffConversion_Data.dll @ 4501e72c; FUN_4501e72c

uint __thiscall FUN_4501e72c(void *this,uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_1c;
  uint local_18;
  undefined8 local_14;
  double local_c;
  
  FUN_4501df58(&local_1c,0,0,0,0,0,0);
  *param_2 = local_1c;
  param_2[1] = local_18;
  *(undefined8 *)(param_2 + 2) = local_14;
  if (param_1 < 7) {
    local_c = *(double *)this;
    uVar1 = FUN_4501d4fe(&local_c);
    if (uVar1 != param_1) {
      iVar2 = (uVar1 - param_1) + 7;
      if ((int)param_1 < (int)uVar1) {
        iVar2 = uVar1 - param_1;
      }
      FUN_4501df58(&local_1c,0,0,iVar2,0,0,0);
      *param_2 = local_1c;
      param_2[1] = local_18;
      *(undefined8 *)(param_2 + 2) = local_14;
      uVar1 = local_18;
    }
    local_18 = CONCAT31((int3)(uVar1 >> 8),1);
  }
  else {
    local_18 = local_18 & 0xffffff00;
  }
  return local_18;
}


