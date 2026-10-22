// Source: CLCiffConversion_Data.dll @ 45018bf2; FUN_45018bf2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall
FUN_45018bf2(void *this,uint param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uStackY_28;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 0;
  iVar3 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar3 + 0x40 + (int)this) = param_1;
  uStackY_28 = 0x45018c24;
  FUN_45008a06((void *)((int)this + iVar3 + 0x44),&param_2);
  puVar2 = (undefined4 *)auStack_20;
  *(undefined2 *)(iVar3 + 0x48 + (int)this) = 0xd;
  *(undefined4 *)(iVar3 + 0x50 + (int)this) = param_3;
  *(undefined1 *)(iVar3 + 0x58 + (int)this) = param_4;
  *(undefined4 *)(iVar3 + 0x5c + (int)this) = param_5;
  *(undefined4 *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = param_6;
  *(undefined1 *)(iVar3 + 100 + (int)this) = param_7;
  *(undefined1 *)(iVar3 + 0x65 + (int)this) = 1;
  piVar1 = *(int **)(iVar3 + 0x50 + (int)this);
  if (piVar1 != (int *)0x0) {
    puVar2 = &uStackY_28;
    uStackY_28 = 0x45018c67;
    (**(code **)(*piVar1 + 4))();
  }
  *(undefined4 *)((int)puVar2 + -4) = 0x45018c6f;
  FUN_45002256(&param_2);
  *(undefined4 *)((int)puVar2 + -4) = 0x45018c74;
  return;
}


