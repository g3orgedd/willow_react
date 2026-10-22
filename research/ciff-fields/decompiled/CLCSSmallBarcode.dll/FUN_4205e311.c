// Source: CLCSSmallBarcode.dll @ 4205e311; FUN_4205e311

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_4205e311(void *this,int *param_1)

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
  local_8 = 0x4205e31d;
  uStack_24 = *(undefined4 *)((int)this + 0x14);
  piStack_28 = (int *)*param_1;
  puVar5 = &uStack_2c;
  uStack_2c = 0x4205e32e;
  (**(code **)(*piStack_28 + 0xac))();
  puVar5[-1] = *piVar3;
  puVar5[-2] = 0x4205e338;
  CComQIPtr<>(&param_1,(undefined4 *)puVar5[-1]);
  piVar3 = param_1;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    puVar5[-1] = 0x32;
    puVar5[-2] = piVar3;
    pcVar2 = *(code **)(iVar1 + 0x160);
    puVar6 = puVar5 + -3;
    puVar5[-3] = 0x4205e34f;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)((int)puVar6 + -4) = 0;
    *(int **)((int)puVar6 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x1b0);
    puVar7 = (undefined1 *)((int)puVar6 + -0xc);
    *(undefined4 *)((int)puVar6 + -0xc) = 0x4205e35c;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar7 + -4) = 1;
    *(int **)(puVar7 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x1b8);
    puVar8 = puVar7 + -0xc;
    *(undefined4 *)(puVar7 + -0xc) = 0x4205e36a;
    (*pcVar2)();
    piVar3 = param_1;
    *(undefined4 *)(puVar8 + -4) = 0;
    *(int **)(puVar8 + -8) = piVar3;
    pcVar2 = *(code **)(*piVar3 + 0x1c0);
    puVar5 = (undefined4 *)(puVar8 + -0xc);
    *(undefined4 *)(puVar8 + -0xc) = 0x4205e377;
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
    *puVar9 = 0x4205e388;
    uVar4 = (*pcVar2)();
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x4205e38f;
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


