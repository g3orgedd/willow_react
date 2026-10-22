// Source: CLCSSmallBarcode.dll @ 4205a31a; FUN_4205a31a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_4205a31a(void *this,int *param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 uStack_2c;
  int *piStack_28;
  undefined4 uStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar3 = param_1;
  uStack_4 = 0;
  local_8 = 0x4205a326;
  uStack_24 = *(undefined4 *)((int)this + 0x14);
  piStack_28 = (int *)*param_1;
  puVar5 = &uStack_2c;
  uStack_2c = 0x4205a337;
  (**(code **)(*piStack_28 + 0xac))();
  puVar5[-1] = *piVar3;
  puVar5[-2] = 0x4205a341;
  CComQIPtr<>(&param_1,(undefined4 *)puVar5[-1]);
  piVar3 = param_1;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    puVar5[-1] = 3;
    puVar5[-2] = piVar3;
    pcVar2 = *(code **)(iVar1 + 0x178);
    puVar6 = puVar5 + -3;
    puVar5[-3] = 0x4205a357;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)((int)puVar6 + -4) = 6;
    *(int **)((int)puVar6 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x180);
    puVar7 = (undefined1 *)((int)puVar6 + -0xc);
    *(undefined4 *)((int)puVar6 + -0xc) = 0x4205a365;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar7 + -4) = 2;
    *(int **)(puVar7 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x170);
    puVar8 = puVar7 + -0xc;
    *(undefined4 *)(puVar7 + -0xc) = 0x4205a373;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar8 + -4) = 0x32;
    *(int **)(puVar8 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x160);
    puVar9 = puVar8 + -0xc;
    *(undefined4 *)(puVar8 + -0xc) = 0x4205a381;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar9 + -4) = 0;
    *(int **)(puVar9 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x198);
    puVar5 = (undefined4 *)(puVar9 + -0xc);
    *(undefined4 *)(puVar9 + -0xc) = 0x4205a38f;
    (*pcVar2)();
  }
  local_8 = 0xffffffff;
  uVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(int **)((int)puVar5 + -4) = param_1;
    pcVar2 = *(code **)(iVar1 + 8);
    puVar10 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar10 = 0x4205a3a0;
    uVar4 = (*pcVar2)();
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x4205a3a7;
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


