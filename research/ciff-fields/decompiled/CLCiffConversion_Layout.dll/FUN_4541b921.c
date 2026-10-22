// Source: CLCiffConversion_Layout.dll @ 4541b921; FUN_4541b921

void __thiscall FUN_4541b921(void *this,undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = FUN_4541d49f(this);
  iVar4 = param_1[1];
  piVar2 = (int *)0x0;
  puVar3 = *(undefined4 **)*param_1;
  if (0 < iVar4) {
    do {
      if ((param_2 == puVar3[2]) && ((int)puVar3[4] <= *param_3 * iVar1)) {
        piVar2 = puVar3 + 2;
      }
      iVar4 = iVar4 + -1;
      puVar3 = (undefined4 *)*puVar3;
    } while (iVar4 != 0);
    if (piVar2 != (int *)0x0) goto LAB_4541b96c;
  }
  piVar2 = *(undefined4 **)*param_1 + 2;
LAB_4541b96c:
  *param_3 = (int)((float)piVar2[2] / (float)iVar1 + DAT_45447488);
  return;
}


