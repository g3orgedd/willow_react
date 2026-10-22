// Source: CLCiffConversion_Data.dll @ 45014266; FUN_45014266

void __thiscall FUN_45014266(void *this,int *param_1,int param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  
  pvVar2 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar2 = *(void **)this;
  }
  uVar1 = 0;
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = param_2 - (int)pvVar2 >> 1;
  }
  if (param_3 != 0) {
    uVar1 = param_3 - param_2 >> 1;
  }
  FUN_45004e21(this,uVar3,uVar1);
  if (7 < *(uint *)((int)this + 0x14)) {
    this = *(void **)this;
  }
  *param_1 = (int)((int)this + uVar3 * 2);
  return;
}


