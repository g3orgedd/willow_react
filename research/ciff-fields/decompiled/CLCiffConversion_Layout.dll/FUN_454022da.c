// Source: CLCiffConversion_Layout.dll @ 454022da; FUN_454022da

undefined8 * __thiscall FUN_454022da(void *this,undefined8 *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  void *pvVar2;
  undefined8 *puVar3;
  uint uVar4;
  
  if (*(uint *)(param_1 + 2) < param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_454294b4("invalid string position");
  }
  uVar4 = *(uint *)(param_1 + 2) - param_2;
  if (param_3 < uVar4) {
    uVar4 = param_3;
  }
  if (this == param_1) {
    FUN_454023e7(this,param_2 + uVar4);
    FUN_45402416(this,0,param_2);
  }
  else {
    bVar1 = FUN_454021f8(this,uVar4,'\0');
    if (bVar1) {
      if (0xf < *(uint *)((int)param_1 + 0x14)) {
        param_1 = *(undefined8 **)param_1;
      }
      puVar3 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        puVar3 = *(undefined8 **)this;
      }
      if (uVar4 != 0) {
        FUN_45429920(puVar3,(undefined8 *)(param_2 + (int)param_1),uVar4);
      }
      *(uint *)((int)this + 0x10) = uVar4;
      pvVar2 = this;
      if (0xf < *(uint *)((int)this + 0x14)) {
        pvVar2 = *(void **)this;
      }
      *(undefined1 *)((int)pvVar2 + uVar4) = 0;
    }
  }
  return this;
}


