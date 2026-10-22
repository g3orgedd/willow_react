// Source: CLCSSmallBarcode.dll @ 42034693; FUN_42034693

void __thiscall
FUN_42034693(void *this,char param_1,char param_2,int *param_3,int *param_4,uint *param_5,
            int param_6,uint param_7,uint param_8,int param_9)

{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 0x94) * param_9;
  if (param_1 == '\0') {
    FUN_4202c0b6(this,param_5,param_6,param_7,param_8,*param_3,uVar1);
    if (param_2 == '\0') {
LAB_420346e3:
      *param_3 = *param_3 + uVar1;
      return;
    }
  }
  else {
    FUN_42033b1d(this,(int)param_5,param_8,(uint *)*param_4,uVar1);
    param_3 = param_4;
    if (param_2 != '\0') goto LAB_420346e3;
  }
  *param_3 = *param_3 - uVar1;
  return;
}


