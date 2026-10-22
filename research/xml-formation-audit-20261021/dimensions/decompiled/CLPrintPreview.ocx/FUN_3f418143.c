// Source: CLPrintPreview.ocx @ 3f418143; FUN_3f418143

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_3f418143(void *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  VARIANTARG local_30;
  undefined4 local_1c;
  int *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x3f41814f;
  if (param_2 == 0) {
    iVar3 = *(int *)((int)this + 0x1ac);
    if (*(int *)((int)this + 0x1ac) <= param_1) {
      iVar3 = param_1;
      if (*(int *)((int)this + 0x1a8) < param_1) {
        iVar3 = *(int *)((int)this + 0x1a8);
      }
    }
    *(int *)((int)this + 0x1c0) = iVar3;
    *(int *)((int)this + 0x1c4) = iVar3;
  }
  else {
    local_1c = *(undefined4 *)((int)this + 0x1b4);
    uVar1 = *(undefined4 *)((int)this + 0x1b0);
    if (*(int *)((int)this + 0x1dc) == 0) {
      FUN_3f4272e0((uint *)&local_30,0,0x10);
      VariantInit(&local_30);
      local_8 = 0;
      (**(code **)(**(int **)((int)this + 0xe0) + 0x30))
                (*(int **)((int)this + 0xe0),*(undefined4 *)((int)this + 0x11c),&local_30);
      CComQIPtr<>(&local_18,(undefined4 *)local_30.n1._8_4_);
      local_8._0_1_ = 1;
      (**(code **)(*local_18 + 0x3c))(local_18,&param_1);
      (**(code **)(*local_18 + 0x44))(local_18,local_14);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8 = 0xffffffff;
      VariantClear(&local_30);
    }
    else {
      param_1 = *(int *)((int)this + 0x14c);
      local_14[0] = *(int *)((int)this + 0x150);
    }
    if (*(int *)((int)this + 0x130) == 1) {
      param_1 = (int)(((float)param_1 * *(float *)((int)this + 0x13c)) /
                     *(float *)((int)this + 0x134));
      local_14[0] = (int)(((float)local_14[0] * *(float *)((int)this + 0x140)) /
                         *(float *)((int)this + 0x138));
    }
    else {
      FUN_3f402fa5(&local_18);
      piVar6 = *(int **)((int)this + 0xe8);
      local_8 = 2;
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))(piVar6);
      }
      param_1 = FUN_3f403cfa(param_1,0.0,piVar6);
      piVar6 = *(int **)((int)this + 0xe8);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))(piVar6);
      }
      local_14[0] = FUN_3f403cfa(local_14[0],0.0,piVar6);
      local_8 = 0xffffffff;
      FUN_3f40335c(&local_18);
    }
    *(int *)((int)this + 0x1b0) = param_1;
    *(int *)((int)this + 0x1b4) = local_14[0];
    *(undefined4 *)((int)this + 0x1b0) = uVar1;
    fVar5 = (float)(*(int *)((int)this + 0x170) - *(int *)((int)this + 0x168)) / (float)param_1;
    *(undefined4 *)((int)this + 0x1b4) = local_1c;
    fVar4 = (float)(*(int *)((int)this + 0x174) - *(int *)((int)this + 0x16c)) / (float)local_14[0];
    if (fVar4 <= fVar5) {
      fVar5 = fVar4;
    }
    iVar2 = (int)(((float)*(int *)((int)this + 0x1c8) * fVar5 * _DAT_3f440b0c) / _DAT_3f440b0c);
    iVar3 = *(int *)((int)this + 0x1a8);
    if (iVar2 < *(int *)((int)this + 0x1a8)) {
      iVar3 = iVar2;
    }
    iVar2 = *(int *)((int)this + 0x1ac);
    if (*(int *)((int)this + 0x1ac) < iVar3) {
      iVar2 = iVar3;
    }
    *(int *)((int)this + 0x1c0) = iVar2;
    *(int *)((int)this + 0x1c4) = iVar2;
    FUN_3f415d9b((void *)((int)this + 0xb4),*(undefined4 *)((int)this + 0x178),
                 *(undefined4 *)((int)this + 0x180));
  }
  FUN_3f40d1f7((int)this + 4);
  FUN_3f417e69(this);
  FUN_3f403715(0x3f443408);
  FUN_3f415fe3((void *)((int)this + 0xb4),*(undefined4 *)((int)this + 0x1c0));
  if (param_2 != 0) {
    FUN_3f415d9b((void *)((int)this + 0xb4),*(undefined4 *)((int)this + 0x178),
                 *(undefined4 *)((int)this + 0x180));
  }
  return;
}


