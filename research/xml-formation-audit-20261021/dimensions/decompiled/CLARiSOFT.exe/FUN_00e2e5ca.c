// Source: CLARiSOFT.exe @ 00e2e5ca; FUN_00e2e5ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_00e2e5ca(void *this,void *param_1)

{
  int iVar1;
  void *this_00;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *extraout_EAX;
  int *piVar7;
  BSTR pOVar8;
  BSTR pOVar9;
  int local_1c [2];
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0xc;
  puVar2 = &LAB_00eeb3f9;
  if ((param_1 != (void *)0x0) && (*(int *)((int)this + 0x19c) != 0)) {
    local_14[0] = (BSTR)0x0;
    local_8 = 0;
    if (*(int *)((int)param_1 + 4) != 0) {
      (**(code **)(**(int **)((int)param_1 + 4) + 0x1c))(*(int **)((int)param_1 + 4),local_14);
    }
    piVar3 = (int *)FUN_00e77808((void *)((int)this + 4),0);
    if (*piVar3 == 0) {
      param_1 = (void *)0x0;
    }
    else {
      param_1 = (void *)(*piVar3 + -100);
    }
    if (param_1 != (void *)0x0) {
      iVar5 = *(int *)((int)this + 0x194);
      iVar1 = *(int *)((int)this + 400);
      uVar4 = FUN_00e3e85d((int)param_1);
      if (uVar4 < (uint)(iVar5 - iVar1 >> 2)) {
        iVar5 = FUN_00e3e85d((int)param_1);
        FUN_00e677b0(*(void **)(*(int *)((int)this + 400) + iVar5 * 4),'\0');
        iVar5 = FUN_00e3e85d((int)param_1);
        FUN_00e683f3(*(void **)(*(int *)((int)this + 400) + iVar5 * 4),this_00);
        FUN_00e37ef4(this,this_00);
        piVar3 = *(int **)((int)this + 0x19c);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 4))(piVar3);
        }
        piVar7 = *(int **)((int)this + 0x160);
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        FUN_00e60cce(this_00,local_1c,piVar7,piVar3);
        pOVar9 = *(BSTR *)((int)this + 0x160);
        if (pOVar9 != (BSTR)0x0) {
          (**(code **)(*(int *)pOVar9 + 4))(pOVar9);
        }
        pOVar8 = *(BSTR *)((int)this + 0x19c);
        if (pOVar8 != (BSTR)0x0) {
          (**(code **)(*(int *)pOVar8 + 4))(pOVar8);
        }
        uVar6 = FUN_00eb1fd0((void *)((int)this + 0x1ac),pOVar8,pOVar9);
        *(undefined4 *)((int)this + 0x28) = uVar6;
      }
    }
    SysFreeString(local_14[0]);
    puVar2 = extraout_EAX;
  }
  return puVar2;
}


