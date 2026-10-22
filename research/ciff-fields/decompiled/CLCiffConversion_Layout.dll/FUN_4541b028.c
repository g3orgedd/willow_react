// Source: CLCiffConversion_Layout.dll @ 4541b028; FUN_4541b028

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __fastcall FUN_4541b028(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *local_24;
  byte *local_20;
  uint local_1c;
  byte *local_18;
  byte *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x4541b034;
  if (*(char *)(param_1 + 0x15) == '\0') {
    uVar4 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2;
    *(undefined1 *)(param_1 + 0x14) = 0;
    if (1 < uVar4) {
      piVar1 = (int *)FUN_45421dcf(**(undefined4 **)(param_1 + 0x18));
      FUN_45402a2f(&local_24,piVar1);
      local_8 = 0;
      piVar1 = (int *)FUN_45425d80(**(int **)(param_1 + 0x18));
      FUN_45402a2f(&local_20,piVar1);
      local_8._0_1_ = 1;
      uVar2 = 1;
      while ((local_1c = uVar2, *(char *)(param_1 + 0x14) == '\0' && (uVar2 < uVar4))) {
        piVar1 = (int *)FUN_45421dcf(*(undefined4 *)(*(int *)(param_1 + 0x18) + uVar2 * 4));
        FUN_45402a2f(&local_18,piVar1);
        local_8 = CONCAT31(local_8._1_3_,2);
        piVar1 = (int *)FUN_45425d80(*(int *)(*(int *)(param_1 + 0x18) + uVar2 * 4));
        FUN_45402a2f(local_14,piVar1);
        iVar3 = FUN_4542cae1(local_18,local_24);
        if (iVar3 == 0) {
          iVar3 = FUN_4542cae1(local_20,local_14[0]);
          if (iVar3 != 0) goto LAB_4541b0dd;
        }
        else {
LAB_4541b0dd:
          *(undefined1 *)(param_1 + 0x14) = 1;
        }
        FUN_45402c5d((int *)local_14);
        local_8._0_1_ = 1;
        FUN_45402c5d((int *)&local_18);
        uVar2 = local_1c + 1;
      }
      FUN_45402c5d((int *)&local_20);
      FUN_45402c5d((int *)&local_24);
    }
    *(undefined1 *)(param_1 + 0x15) = 1;
  }
  return *(undefined1 *)(param_1 + 0x14);
}


