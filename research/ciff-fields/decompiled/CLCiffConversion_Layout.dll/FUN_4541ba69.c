// Source: CLCiffConversion_Layout.dll @ 4541ba69; FUN_4541ba69

int * __thiscall FUN_4541ba69(void *this,undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = FUN_4541d49f(this);
  piVar3 = (int *)0x0;
  iVar6 = 0;
  puVar2 = *(undefined4 **)*param_1;
  if (0 < (int)param_1[1]) {
    do {
      piVar4 = puVar2 + 2;
      piVar5 = piVar3;
      if (param_2 == *piVar4) {
        if (*param_3 * iVar1 <= (int)puVar2[4]) break;
      }
      else if ((((*piVar4 < param_2) && (*param_3 * iVar1 <= (int)puVar2[4])) &&
               (piVar5 = piVar4, piVar3 != (int *)0x0)) && (piVar5 = piVar3, piVar3[2] == puVar2[4])
              ) {
        piVar5 = piVar4;
      }
      iVar6 = iVar6 + 1;
      puVar2 = (undefined4 *)*puVar2;
      piVar4 = piVar5;
      piVar3 = piVar5;
    } while (iVar6 < (int)param_1[1]);
    if (piVar4 != (int *)0x0) goto LAB_4541bab4;
  }
  piVar4 = *(undefined4 **)*param_1 + 2;
LAB_4541bab4:
  *param_3 = (int)((float)piVar4[2] / (float)iVar1 + DAT_45447488);
  return piVar4;
}


