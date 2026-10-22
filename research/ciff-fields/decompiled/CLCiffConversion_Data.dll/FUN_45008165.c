// Source: CLCiffConversion_Data.dll @ 45008165; FUN_45008165

undefined4 * __thiscall
FUN_45008165(void *this,undefined4 *param_1,undefined4 *param_2,undefined8 *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *local_c;
  
  puVar2 = param_3;
  uVar4 = FID_conflict__Inside(this,(undefined4 *)param_3);
  if ((char)uVar4 == '\0') {
    puVar1 = *(undefined4 **)((int)this + 0x10);
    if (puVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45020fe3("invalid string position");
    }
    puVar6 = (undefined4 *)((int)puVar1 - (int)param_1);
    puVar7 = param_2;
    if (puVar6 < param_2) {
      puVar7 = puVar6;
    }
    if (-param_4 - 1 <= (uint)((int)puVar1 - (int)puVar7)) {
                    /* WARNING: Subroutine does not return */
      FUN_45020fb5("string too long");
    }
    if (param_4 < puVar7) {
      param_2 = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        param_2 = *(undefined4 **)this;
      }
      local_c = this;
      if (7 < *(uint *)((int)this + 0x14)) {
        local_c = *(void **)this;
      }
      FUN_45004edc((undefined8 *)((int)local_c + ((int)param_1 + param_4) * 2),
                   (undefined8 *)((int)param_2 + ((int)param_1 + (int)puVar7) * 2),
                   (int)puVar6 - (int)puVar7);
    }
    if ((param_4 != 0) || (puVar7 != (undefined4 *)0x0)) {
      uVar4 = (*(int *)((int)this + 0x10) - (int)puVar7) + param_4;
      bVar3 = FUN_4500458e(this,uVar4,'\0');
      if (bVar3) {
        if (puVar7 < param_4) {
          param_2 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
            param_2 = *(undefined4 **)this;
          }
          param_3 = this;
          if (7 < *(uint *)((int)this + 0x14)) {
            param_3 = *(undefined8 **)this;
          }
          FUN_45004edc((undefined8 *)((int)param_3 + ((int)param_1 + param_4) * 2),
                       (undefined8 *)((int)param_2 + ((int)param_1 + (int)puVar7) * 2),
                       (int)puVar6 - (int)puVar7);
        }
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar5 = *(void **)this;
        }
        copy((undefined8 *)((int)pvVar5 + (int)param_1 * 2),puVar2,param_4);
        *(uint *)((int)this + 0x10) = uVar4;
        pvVar5 = this;
        if (7 < *(uint *)((int)this + 0x14)) {
          pvVar5 = *(void **)this;
        }
        *(undefined2 *)((int)pvVar5 + uVar4 * 2) = 0;
      }
    }
  }
  else {
    pvVar5 = this;
    if (7 < *(uint *)((int)this + 0x14)) {
      pvVar5 = *(void **)this;
    }
    this = FUN_45007e71(this,param_1,(uint)param_2,this,
                        (undefined4 *)((int)param_3 - (int)pvVar5 >> 1),param_4);
  }
  return this;
}


