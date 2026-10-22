// Source: CLCSSmallBarcode.dll @ 4200b8d7; FUN_4200b8d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 __thiscall FUN_4200b8d7(void *this,int *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0x4200b8e3;
  *(undefined4 *)((int)this + 0x108) = 0;
  piVar5 = (int *)FUN_4200b92e(this,param_1);
  puVar3 = auStack_20;
  param_2 = piVar5;
  if (piVar5 != (int *)0x0) {
    puVar3 = &stack0xffffffd8;
    (**(code **)(*piVar5 + 4))();
  }
  local_8 = 0;
  *(int ***)(puVar3 + -4) = &param_2;
  *(undefined4 *)(puVar3 + -8) = 0x4200b916;
  FUN_4200c0e3(this,*(int **)(puVar3 + -4));
  local_8 = 0xffffffff;
  if (piVar5 != (int *)0x0) {
    iVar1 = *piVar5;
    *(int **)(puVar3 + -4) = piVar5;
    pcVar2 = *(code **)(iVar1 + 8);
    puVar4 = (undefined4 *)(puVar3 + -8);
    puVar3 = puVar3 + -8;
    *puVar4 = 0x4200b924;
    (*pcVar2)();
  }
  *(undefined4 *)(puVar3 + -4) = 0x4200b92b;
  return extraout_EAX;
}


