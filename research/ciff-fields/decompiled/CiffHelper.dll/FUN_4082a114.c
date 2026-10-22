// Source: CiffHelper.dll @ 4082a114; FUN_4082a114

uint __thiscall FUN_4082a114(void *this,uint param_1,int param_2)

{
  uint in_EAX;
  double *pdVar1;
  undefined4 uVar2;
  int local_34 [2];
  undefined8 local_2c;
  int local_24 [2];
  undefined8 local_1c;
  double local_14;
  double local_c;
  
  if ((2 < param_1) || (in_EAX = param_2 - 1, 0x1e < in_EAX)) {
    return in_EAX & 0xffffff00;
  }
  pdVar1 = (double *)0xffc8d366;
  local_c = *(double *)this;
  local_34[1] = 0xffc8d366;
  local_34[0] = -0x372c9a;
  local_2c = DAT_408500e0;
  local_24[1] = 0xffc8d366;
  local_24[0] = -0x372c9a;
  local_1c = DAT_408500e0;
  if (param_1 == 0) {
    FUN_4082a2cc(this,param_2,local_34);
LAB_4082a1bf:
    pdVar1 = FUN_408294b5(&local_14,&local_c,local_34);
  }
  else {
    if (param_1 == 1) {
      FUN_4082a456(this,param_2,local_24);
    }
    else {
      if (param_1 != 2) goto LAB_4082a1d7;
      FUN_4082a2cc(this,param_2,local_34);
      FUN_4082a456(this,param_2,local_24);
      uVar2 = FUN_4082a076(local_34,local_24);
      if ((char)uVar2 == '\0') goto LAB_4082a1bf;
    }
    pdVar1 = FUN_408293bc(&local_14,&local_c,local_24);
  }
  local_c = *pdVar1;
LAB_4082a1d7:
  *(double *)this = local_c;
  return CONCAT31((int3)((uint)pdVar1 >> 8),1);
}


