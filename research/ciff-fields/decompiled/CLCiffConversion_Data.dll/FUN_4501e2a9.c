// Source: CLCiffConversion_Data.dll @ 4501e2a9; FUN_4501e2a9

uint __thiscall FUN_4501e2a9(void *this,uint param_1,uint param_2,uint param_3)

{
  uint in_EAX;
  uint uVar1;
  
  if ((param_2 != 2) && (param_2 == 1)) {
    in_EAX = (int)param_3 / 7;
    param_3 = (int)param_3 % 7;
  }
  if (((param_2 < 3) && (param_1 < 3)) && ((param_2 != 2 || (in_EAX = param_3 - 1, in_EAX < 0x1f))))
  {
    uVar1 = 0;
    if (param_2 == 0) {
      uVar1 = 1;
    }
    else if (param_2 == 1) {
      uVar1 = FUN_4501e3e4(this,param_1,param_3);
    }
    else if (param_2 == 2) {
      uVar1 = FUN_4501e30f(this,param_1,param_3);
    }
  }
  else {
    uVar1 = in_EAX & 0xffffff00;
  }
  return uVar1;
}


