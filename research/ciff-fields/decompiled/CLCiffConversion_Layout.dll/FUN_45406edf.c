// Source: CLCiffConversion_Layout.dll @ 45406edf; FUN_45406edf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45406edf(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int extraout_EAX;
  float10 fVar7;
  int *local_3c;
  undefined4 local_38;
  void *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x45406eeb;
  local_34 = this;
  (**(code **)(**(int **)((int)this + 0x34) + 0x54))(*(int **)((int)this + 0x34),&local_24);
  bVar4 = false;
  local_20 = 0;
  cVar3 = FUN_4540678d((int)this);
  if (cVar3 == '\0') {
    local_18 = 0;
    (**(code **)(**(int **)((int)this + 0x38) + 0x44))(*(int **)((int)this + 0x38),&local_18);
    local_14[0] = 0;
    (**(code **)(**(int **)((int)this + 0x38) + 0x3c))(*(int **)((int)this + 0x38),local_14);
    iVar5 = local_18;
    if (local_24 == 0) {
      fVar7 = FUN_45406d26((int)this);
      iVar6 = local_14[0];
      local_34 = (void *)(float)fVar7;
      local_18 = (int)((float)iVar5 / (float)local_34 + DAT_45447488);
      fVar7 = FUN_45406d0a((int)this);
      local_34 = (void *)(float)fVar7;
      local_14[0] = (int)((float)iVar6 / (float)local_34 + DAT_45447488);
    }
    local_2c = 0;
    (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,&local_2c);
    local_30 = 0;
    (**(code **)(*(int *)*param_1 + 0x5c))((int *)*param_1,&local_30);
    piVar1 = *(int **)((int)this + 0x38);
    if (piVar1 != (int *)0x0) {
      local_20 = 0;
      iVar5 = (**(code **)(*piVar1 + 0x3ec))(piVar1,&local_20);
      if (local_20 != 0) goto LAB_45407108;
    }
    piVar1 = *(int **)((int)this + 0x38);
    if (piVar1 != (int *)0x0) {
      local_28 = 0;
      iVar5 = (**(code **)(*piVar1 + 0x41c))(piVar1,&local_28);
      if ((-1 < iVar5) && (local_28 != 0)) {
        bVar4 = true;
      }
    }
    iVar5 = local_2c;
    if ((local_18 < local_2c) &&
       ((!bVar4 ||
        (iVar5 = CONCAT31((int3)((uint)local_2c >> 8),local_2c <= local_14[0]),
        local_2c > local_14[0])))) {
      iVar5 = (**(code **)(*(int *)*param_1 + 0x68))((int *)*param_1,local_18);
    }
    if (local_14[0] < local_30) {
      iVar5 = (**(code **)(*(int *)*param_1 + 0x60))((int *)*param_1,local_14[0]);
    }
  }
  else {
    local_38 = 0;
    local_3c = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
    local_8 = 0;
    FUN_45406d62(param_1,&local_3c);
    piVar2 = local_3c;
    for (piVar1 = (int *)*local_3c; piVar1 != piVar2; piVar1 = (int *)*piVar1) {
      iVar5 = piVar1[2];
      local_30 = iVar5;
      bVar4 = FUN_45406d42(iVar5);
      if (bVar4) {
        iVar5 = FUN_4541cd30(iVar5);
        iVar6 = FUN_4541cd14(local_30);
        if (local_20 < iVar6 + iVar5) {
          local_20 = iVar6 + iVar5;
        }
      }
      this = local_34;
    }
    FUN_454065f3((int *)&local_3c);
    (**(code **)(*(int *)*param_1 + 0x40))((int *)*param_1,local_20);
    local_1c = 0;
    (**(code **)(**(int **)((int)this + 0x6c) + 0x24))(*(int **)((int)this + 0x6c),&local_1c);
    iVar5 = local_1c;
    if (local_24 == 0) {
      fVar7 = FUN_45406d26((int)this);
      local_34 = (void *)(float)fVar7;
      local_1c = (int)((float)iVar5 / (float)local_34 + DAT_45447488);
    }
    (**(code **)(*(int *)*param_1 + 0x48))((int *)*param_1,local_1c);
    FUN_454224ff((int *)&local_3c);
    FID_conflict__free(local_3c);
    iVar5 = extraout_EAX;
  }
LAB_45407108:
  return CONCAT31((int3)((uint)iVar5 >> 8),1);
}


