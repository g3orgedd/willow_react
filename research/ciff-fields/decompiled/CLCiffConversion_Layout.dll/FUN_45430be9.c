// Source: CLCiffConversion_Layout.dll @ 45430be9; FUN_45430be9

undefined4 __cdecl FUN_45430be9(int param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 uVar6;
  int iVar7;
  
  piVar2 = param_2;
  if (param_2 == (int *)0x0) {
    _inconsistency();
    terminate();
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  uVar6 = 0;
  iVar7 = 0;
  if (0 < *param_2) {
    param_2 = (int *)0x0;
    uVar6 = 0;
    do {
      piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
      for (iVar3 = *piVar5; in_EAX = iVar3, 0 < iVar3; iVar3 = iVar3 + -1) {
        piVar5 = piVar5 + 1;
        in_EAX = FUN_454310ee((byte *)(piVar2[1] + (int)param_2),(byte *)*piVar5,
                              *(byte **)(param_1 + 0x1c));
        if (in_EAX != 0) {
          uVar6 = 1;
          break;
        }
      }
      iVar7 = iVar7 + 1;
      param_2 = param_2 + 4;
    } while (iVar7 < *piVar2);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),uVar6);
}


