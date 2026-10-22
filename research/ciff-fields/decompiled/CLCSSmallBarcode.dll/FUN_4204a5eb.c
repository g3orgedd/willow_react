// Source: CLCSSmallBarcode.dll @ 4204a5eb; FUN_4204a5eb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_4204a5eb(void *this,int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_1;
  uStack_4 = 0;
  local_8 = 0x4204a5f7;
  uStack_24 = *(undefined4 *)((int)this + 0x14);
  piStack_28 = (int *)*param_1;
  puVar5 = &uStack_2c;
  uStack_2c = 0x4204a608;
  (**(code **)(*piStack_28 + 0xac))();
  puVar5[-1] = *piVar3;
  puVar5[-2] = 0x4204a612;
  CComQIPtr<>(&param_1,(undefined4 *)puVar5[-1]);
  piVar3 = param_1;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    puVar5[-1] = 5;
    puVar5[-2] = piVar3;
    pcVar2 = *(code **)(iVar1 + 0x158);
    puVar6 = puVar5 + -3;
    puVar5[-3] = 0x4204a628;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)((int)puVar6 + -4) = 3;
    *(int **)((int)puVar6 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x168);
    puVar7 = (undefined1 *)((int)puVar6 + -0xc);
    *(undefined4 *)((int)puVar6 + -0xc) = 0x4204a636;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar7 + -4) = 0x32;
    *(int **)(puVar7 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x160);
    puVar8 = puVar7 + -0xc;
    *(undefined4 *)(puVar7 + -0xc) = 0x4204a644;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar8 + -4) = 0;
    *(int **)(puVar8 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x10c);
    puVar5 = (undefined4 *)(puVar8 + -0xc);
    *(undefined4 *)(puVar8 + -0xc) = 0x4204a652;
    (*pcVar2)();
  }
  local_8 = 0xffffffff;
  uVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(int **)((int)puVar5 + -4) = param_1;
    pcVar2 = *(code **)(iVar1 + 8);
    puVar9 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar9 = 0x4204a663;
    uVar4 = (*pcVar2)();
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x4204a66a;
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


