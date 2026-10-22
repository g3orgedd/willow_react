// Source: CLCiffConversion_Layout.dll @ 4541b99a; FUN_4541b99a

int * __thiscall FUN_4541b99a(void *this,undefined4 *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int local_10;
  
  iVar3 = FUN_4541d49f(this);
  piVar7 = (int *)0x0;
  local_10 = 0x7fffffff;
  iVar2 = *param_3;
  iVar5 = param_1[1];
  puVar6 = *(undefined4 **)*param_1;
  if (0 < iVar5) {
    do {
      piVar1 = puVar6 + 2;
      if (param_2 == *piVar1) {
        iVar4 = FUN_45429905(puVar6[4] - iVar2 * iVar3);
        if (iVar4 <= local_10) {
LAB_4541b9f3:
          piVar7 = piVar1;
          local_10 = iVar4;
        }
      }
      else if ((*piVar1 < param_2) &&
              (iVar4 = FUN_45429905(puVar6[4] - iVar2 * iVar3), iVar4 <= local_10)) {
        if (piVar7 == (int *)0x0) goto LAB_4541b9f3;
        if (piVar7[2] == puVar6[4]) {
          piVar7 = piVar1;
        }
      }
      puVar6 = (undefined4 *)*puVar6;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (piVar7 != (int *)0x0) goto LAB_4541ba39;
  }
  piVar7 = (int *)(*(int *)*param_1 + 8);
LAB_4541ba39:
  *param_3 = (int)((float)piVar7[2] / (float)iVar3 + DAT_45447488);
  return piVar7;
}


