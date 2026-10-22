// Source: CLARiSOFT.exe @ 00e311ec; FUN_00e311ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e311ec(void *this,BSTR param_1,void *param_2,void *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *this_00;
  undefined4 local_20;
  int local_1c;
  void *local_18;
  undefined4 *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0xe311f8;
  local_18 = this;
  piVar2 = (int *)FUN_00e77808((void *)((int)this + 4),0);
  if (*piVar2 == 0) {
    this_00 = (void *)0x0;
  }
  else {
    this_00 = (void *)(*piVar2 + -100);
  }
  if (this_00 != (void *)0x0) {
    iVar3 = FUN_00e3e85d((int)this_00);
    iVar4 = FUN_00e68567(*(int *)(*(int *)((int)this + 400) + iVar3 * 4));
    local_1c = iVar4;
    iVar3 = FUN_00e3e85d((int)this_00);
    FUN_00e68547(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),local_14);
    iVar3 = local_1c;
    if (0 < iVar4) {
      do {
        puVar1 = (undefined4 *)*local_14[0];
        if ((BSTR)local_14[0][2] != param_1) {
          puVar1 = local_14[0] + 2;
          local_14[0] = (undefined4 *)*local_14[0];
          FUN_00e3ea34(this_00,(void *)*puVar1);
          puVar1 = local_14[0];
        }
        local_14[0] = puVar1;
        iVar3 = iVar3 + -1;
        this = local_18;
      } while (iVar3 != 0);
    }
    piVar2 = *(int **)((int)this + 0x160);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    local_8 = 0;
    iVar3 = FUN_00e3e85d((int)this_00);
    local_8 = 0xffffffff;
    FUN_00e67152(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),param_2,param_3,param_1,piVar2);
    iVar3 = FUN_00e3e85d((int)this_00);
    iVar3 = FUN_00e68567(*(int *)(*(int *)((int)this + 400) + iVar3 * 4));
    iVar4 = FUN_00e3e85d((int)this_00);
    local_14[0] = (undefined4 *)
                  FUN_00e68547(*(void **)(*(int *)((int)this + 400) + iVar4 * 4),&local_20);
    local_14[0] = (undefined4 *)*local_14[0];
    if (0 < iVar3) {
      do {
        puVar1 = (undefined4 *)*local_14[0];
        if ((BSTR)local_14[0][2] != param_1) {
          puVar1 = local_14[0] + 2;
          local_14[0] = (undefined4 *)*local_14[0];
          FUN_00e3ea34(this_00,(void *)*puVar1);
          puVar1 = local_14[0];
        }
        local_14[0] = puVar1;
        iVar3 = iVar3 + -1;
        this = local_18;
      } while (iVar3 != 0);
    }
    FUN_00e2b99e((int)this);
    FUN_00e3ea34(this_00,param_1);
  }
  return;
}


