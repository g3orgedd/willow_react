// Source: CLARiSOFT.exe @ 00e34f42; FUN_00e34f42

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_00e34f42(int param_1)

{
  int iVar1;
  int iVar2;
  BYTE *extraout_ECX;
  BYTE *extraout_ECX_00;
  BYTE *pBVar3;
  int *piVar4;
  BYTE *pBVar5;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0xe34f4e;
  iVar1 = *(int *)(param_1 + 0x13c);
  iVar2 = *(int *)(param_1 + 0x138);
  if (*(int *)(param_1 + 0x22c) == 0) {
    FUN_00eae6d1(&local_18);
    local_8 = 0;
    piVar4 = *(int **)(param_1 + 0x160);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))();
    }
    iVar1 = FUN_00eae95c(iVar1,1.4013e-45,piVar4);
    piVar4 = *(int **)(param_1 + 0x160);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))();
    }
    iVar2 = FUN_00eae95c(iVar2,0.0,piVar4);
    local_8 = 0xffffffff;
    FUN_00eae7b2(&local_18);
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    FUN_00e03bc2(&local_18,*(LPCWSTR *)(*(int *)(param_1 + 0x158) + 0x24));
    local_8 = 1;
    FUN_00e03bc2(local_14,*(LPCWSTR *)(*(int *)(param_1 + 0x158) + 4));
    local_8._0_1_ = 2;
    pBVar5 = extraout_ECX;
    FUN_00e06f2b(&stack0xffffffcc,local_14);
    local_8._0_1_ = 3;
    pBVar3 = extraout_ECX_00;
    FUN_00e06f2b(&stack0xffffffc8,&local_18);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00e35033(iVar1,iVar2,pBVar3,pBVar5);
    FUN_00e01f81(local_14);
    FUN_00e01f81(&local_18);
  }
  return;
}


