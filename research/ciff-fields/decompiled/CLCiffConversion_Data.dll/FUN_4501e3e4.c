// Source: CLCiffConversion_Data.dll @ 4501e3e4; FUN_4501e3e4

uint __thiscall FUN_4501e3e4(void *this,uint param_1,uint param_2)

{
  double *pdVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte bVar4;
  int local_34 [2];
  undefined8 local_2c;
  int local_24 [2];
  undefined8 local_1c;
  double local_14;
  double local_c;
  
  if ((2 < param_1) || (6 < param_2)) {
    return param_1 & 0xffffff00;
  }
  local_c = *(double *)this;
  bVar4 = 0;
  local_34[1] = 0xffc8d366;
  local_34[0] = -0x372c9a;
  local_2c = DAT_45040c68;
  local_24[1] = 0xffc8d366;
  local_24[0] = -0x372c9a;
  local_1c = DAT_45040c68;
  if (param_1 == 0) {
    uVar2 = FUN_4501e5c2(this,param_2,local_34);
    bVar4 = (byte)uVar2;
LAB_4501e49c:
    pdVar1 = FUN_4501d1ec(&local_14,&local_c,local_34);
  }
  else {
    if (param_1 == 1) {
      uVar2 = FUN_4501e72c(this,param_2,local_24);
      bVar4 = (byte)uVar2;
    }
    else {
      pdVar1 = (double *)(param_1 - 2);
      if (pdVar1 != (double *)0x0) goto LAB_4501e4b4;
      uVar2 = FUN_4501e5c2(this,param_2,local_34);
      uVar3 = FUN_4501e72c(this,param_2,local_24);
      bVar4 = (byte)uVar2 & (byte)uVar3;
      uVar2 = FUN_4501e271(local_34,local_24);
      if ((char)uVar2 == '\0') goto LAB_4501e49c;
    }
    pdVar1 = FUN_4501d17f(&local_14,&local_c,local_24);
  }
  local_c = *pdVar1;
LAB_4501e4b4:
  *(double *)this = local_c;
  return CONCAT31((int3)((uint)pdVar1 >> 8),bVar4);
}


