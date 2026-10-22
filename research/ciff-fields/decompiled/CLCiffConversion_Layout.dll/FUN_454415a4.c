// Source: CLCiffConversion_Layout.dll @ 454415a4; FUN_454415a4

undefined4 * __cdecl FUN_454415a4(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar5 = 0;
  puVar3 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = *piVar2;
    }
    puVar3 = FUN_454375c4(iVar5 + 1,4);
    if (puVar3 == (undefined4 *)0x0) {
      __amsg_exit(9);
    }
    pcVar4 = (char *)*param_1;
    puVar6 = puVar3;
    if (pcVar4 != (char *)0x0) {
      do {
        pcVar4 = FUN_45441bb0(pcVar4);
        *puVar6 = pcVar4;
        puVar6 = puVar6 + 1;
        pcVar4 = *(char **)(((int)param_1 - (int)puVar3) + (int)puVar6);
      } while (pcVar4 != (char *)0x0);
    }
    *puVar6 = 0;
  }
  return puVar3;
}


