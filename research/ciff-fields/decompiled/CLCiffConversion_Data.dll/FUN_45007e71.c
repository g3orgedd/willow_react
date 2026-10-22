// Source: CLCiffConversion_Data.dll @ 45007e71; FUN_45007e71

undefined4 * __thiscall
FUN_45007e71(void *this,undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
            uint param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  void *pvVar6;
  undefined8 *puVar7;
  void *pvVar8;
  uint uVar9;
  undefined8 *puVar10;
  
  puVar1 = param_4;
  puVar4 = *(undefined4 **)((int)this + 0x10);
  if ((puVar4 < param_1) || ((undefined4 *)param_3[4] < param_4)) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fe3("invalid string position");
  }
  uVar9 = (int)puVar4 - (int)param_1;
  if (uVar9 < param_2) {
    param_2 = uVar9;
  }
  uVar2 = (int)param_3[4] - (int)param_4;
  if (uVar2 < param_5) {
    param_5 = uVar2;
  }
  if (-param_5 - 1 <= (int)puVar4 - param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fb5("string too long");
  }
  uVar9 = uVar9 - param_2;
  puVar3 = (undefined4 *)(param_5 + ((int)puVar4 - param_2));
  if (puVar4 < puVar3) {
    FUN_4500458e(this,(uint)puVar3,'\0');
  }
  if (this != param_3) {
    pvVar6 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar6 = *(void **)this;
    }
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar5 = *(void **)this;
    }
    FUN_45004edc((undefined8 *)((int)pvVar5 + (param_5 + (int)param_1) * 2),
                 (undefined8 *)((int)pvVar6 + (param_2 + (int)param_1) * 2),uVar9);
    if (7 < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    pvVar6 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar6 = *(void **)this;
    }
    copy((undefined8 *)((int)pvVar6 + (int)param_1 * 2),
         (undefined8 *)((int)param_3 + (int)param_4 * 2),param_5);
    goto LAB_4500812b;
  }
  param_3 = this;
  if (param_2 < param_5) {
    pvVar6 = this;
    if (param_1 < param_4) {
      puVar4 = (undefined4 *)(param_2 + (int)param_1);
      if (param_4 < puVar4) {
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar6 = *(void **)this;
        }
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar5 = *(void **)this;
        }
        FUN_45004edc((undefined8 *)((int)pvVar5 + (int)param_1 * 2),
                     (undefined8 *)((int)pvVar6 + (int)param_4 * 2),param_2);
        pvVar6 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar6 = *(void **)this;
        }
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar5 = *(void **)this;
        }
        FUN_45004edc((undefined8 *)((int)pvVar5 + (param_5 + (int)param_1) * 2),
                     (undefined8 *)((int)pvVar6 + (int)puVar4 * 2),uVar9);
        param_1 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          param_1 = *(undefined4 **)this;
        }
        pvVar6 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar6 = *(void **)this;
        }
        uVar9 = param_5 - param_2;
        puVar10 = (undefined8 *)((int)param_1 + ((int)param_4 + param_5) * 2);
        puVar7 = (undefined8 *)((int)pvVar6 + (int)puVar4 * 2);
        goto LAB_45008125;
      }
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar5 = *(void **)this;
      }
      pvVar8 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar8 = *(void **)this;
      }
      FUN_45004edc((undefined8 *)((int)pvVar8 + (param_5 + (int)param_1) * 2),
                   (undefined8 *)((int)pvVar5 + (int)puVar4 * 2),uVar9);
      if (7 < *(uint *)((int)this + 0x14)) {
        param_3 = *(undefined4 **)this;
      }
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar6 = *(void **)this;
      }
      param_4 = (undefined4 *)((int)param_4 + (param_5 - param_2));
    }
    else {
      if (7 < *(uint *)((int)this + 0x14)) {
        param_3 = *(undefined4 **)this;
      }
      pvVar5 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar5 = *(void **)this;
      }
      FUN_45004edc((undefined8 *)((int)pvVar5 + (param_5 + (int)param_1) * 2),
                   (undefined8 *)((int)param_3 + (param_2 + (int)param_1) * 2),uVar9);
      param_3 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        param_3 = *(undefined4 **)this;
      }
      if (7 < *(uint *)((int)this + 0x14)) {
        pvVar6 = *(void **)this;
      }
    }
    puVar10 = (undefined8 *)((int)param_3 + (int)param_4 * 2);
    puVar7 = (undefined8 *)((int)pvVar6 + (int)param_1 * 2);
    uVar9 = param_5;
  }
  else {
    param_4 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      param_4 = *(undefined4 **)this;
    }
    if (7 < *(uint *)((int)this + 0x14)) {
      param_3 = *(undefined4 **)this;
    }
    FUN_45004edc((undefined8 *)((int)param_3 + (int)param_1 * 2),
                 (undefined8 *)((int)param_4 + (int)puVar1 * 2),param_5);
    pvVar6 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar6 = *(void **)this;
    }
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar5 = *(void **)this;
    }
    puVar10 = (undefined8 *)((int)pvVar6 + (param_2 + (int)param_1) * 2);
    puVar7 = (undefined8 *)((int)pvVar5 + (param_5 + (int)param_1) * 2);
  }
LAB_45008125:
  FUN_45004edc(puVar7,puVar10,uVar9);
LAB_4500812b:
  *(undefined4 **)((int)this + 0x10) = puVar3;
  pvVar6 = this;
  if (7 < *(uint *)((int)this + 0x14)) {
    pvVar6 = *(void **)this;
  }
  *(undefined2 *)((int)pvVar6 + (int)puVar3 * 2) = 0;
  return this;
}


