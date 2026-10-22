// Source: CLCiffConversion_Data.dll @ 4502c714; FUN_4502c714

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

char __cdecl FUN_4502c714(int param_1,int *param_2,uint *param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined8 *puVar3;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  uint uVar4;
  
  if (((param_3[1] == 0) || (*(char *)(param_3[1] + 8) == '\0')) ||
     ((param_3[2] == 0 && ((*param_3 & 0x80000000) == 0)))) {
    return '\0';
  }
  uVar4 = *param_3;
  if (-1 < (int)uVar4) {
    param_2 = (int *)((int)param_2 + param_3[2] + 0xc);
  }
  if ((((char)uVar4 < '\0') && ((*param_4 & 0x10) != 0)) && (DAT_45055398 != (code *)0x0)) {
    iVar2 = (*DAT_45055398)();
    bVar1 = FUN_45034267(iVar2);
    if ((CONCAT31(extraout_var,bVar1) == 0) ||
       (bVar1 = FUN_45034267((int)param_2), CONCAT31(extraout_var_00,bVar1) == 0))
    goto LAB_4502c8b2;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((uVar4 & 8) == 0) {
      if ((*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          bVar1 = FUN_45034267(iVar2);
          if ((CONCAT31(extraout_var_05,bVar1) != 0) &&
             (bVar1 = FUN_45034267((int)param_2), CONCAT31(extraout_var_06,bVar1) != 0)) {
            uVar4 = *(uint *)(param_4 + 0x14);
            puVar3 = (undefined8 *)___AdjustPointer(*(int *)(param_1 + 0x18),(int *)(param_4 + 8));
            FUN_45021d30((undefined8 *)param_2,puVar3,uVar4);
            return '\0';
          }
        }
        else {
          bVar1 = FUN_45034267(iVar2);
          if (((CONCAT31(extraout_var_07,bVar1) != 0) &&
              (bVar1 = FUN_45034267((int)param_2), CONCAT31(extraout_var_08,bVar1) != 0)) &&
             (bVar1 = FUN_45034267(*(int *)(param_4 + 0x18)), CONCAT31(extraout_var_09,bVar1) != 0))
          {
            return ((*param_4 & 4) != 0) + '\x01';
          }
        }
LAB_4502c8b2:
        _inconsistency();
        return '\0';
      }
      bVar1 = FUN_45034267(iVar2);
      if ((CONCAT31(extraout_var_03,bVar1) == 0) ||
         (bVar1 = FUN_45034267((int)param_2), CONCAT31(extraout_var_04,bVar1) == 0))
      goto LAB_4502c8b2;
      FUN_45021d30((undefined8 *)param_2,*(undefined8 **)(param_1 + 0x18),*(uint *)(param_4 + 0x14))
      ;
      if (*(int *)(param_4 + 0x14) != 4) {
        return '\0';
      }
      if (*param_2 == 0) {
        return '\0';
      }
      iVar2 = *param_2;
      goto LAB_4502c7a5;
    }
    bVar1 = FUN_45034267(iVar2);
    if ((CONCAT31(extraout_var_01,bVar1) == 0) ||
       (bVar1 = FUN_45034267((int)param_2), CONCAT31(extraout_var_02,bVar1) == 0))
    goto LAB_4502c8b2;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  *param_2 = iVar2;
LAB_4502c7a5:
  iVar2 = ___AdjustPointer(iVar2,(int *)(param_4 + 8));
  *param_2 = iVar2;
  return '\0';
}


