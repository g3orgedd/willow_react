// Source: CLCiffConversion_Layout.dll @ 45404a6f; FUN_45404a6f

uint __thiscall FUN_45404a6f(void *this,uint *param_1,uint param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  size_t sVar5;
  
  if ((param_3 != 0) || (*(uint *)((int)this + 0x10) < param_2)) {
    if ((param_2 < *(uint *)((int)this + 0x10)) &&
       (uVar4 = *(uint *)((int)this + 0x10) - param_2, param_3 <= uVar4)) {
      sVar5 = uVar4 + (1 - param_3);
      pvVar1 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        pvVar1 = *(void **)this;
      }
      pvVar1 = (void *)((int)pvVar1 + param_2);
      while (puVar3 = FUN_45404b00(pvVar1,sVar5,(char *)param_1), puVar3 != (uint *)0x0) {
        if ((param_3 == 0) || (iVar2 = FUN_4542b09d(puVar3,param_1,param_3), iVar2 == 0)) {
          if (0xf < *(uint *)((int)this + 0x14)) {
            this = *(void **)this;
          }
          return (int)puVar3 - (int)this;
        }
        sVar5 = (int)pvVar1 + sVar5 + (-1 - (int)puVar3);
        pvVar1 = (void *)((int)puVar3 + 1);
      }
    }
    param_2 = 0xffffffff;
  }
  return param_2;
}


