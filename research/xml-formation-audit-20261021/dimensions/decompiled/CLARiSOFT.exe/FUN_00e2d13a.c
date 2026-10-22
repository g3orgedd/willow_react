// Source: CLARiSOFT.exe @ 00e2d13a; FUN_00e2d13a

void __fastcall FUN_00e2d13a(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_00e77808((void *)(param_1 + 4),0);
  if (*piVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2 + -100;
  }
  FUN_00e384b8((int *)(iVar3 + 0xa0));
  if ((*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400) & 0xfffffffcU) != 0) {
    iVar3 = 0;
    if (0 < (int)(*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400) & 0xfffffffcU)) {
      do {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 400) + iVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
          *(undefined4 *)(*(int *)(param_1 + 400) + iVar3 * 4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x194) - *(int *)(param_1 + 400) >> 2);
    }
    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 400);
  }
  if (*(int *)(param_1 + 0x1e0) != 0) {
    piVar2 = *(int **)(param_1 + 0x1e0);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    piVar2 = *(int **)(param_1 + 0x1e0);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  if (*(int *)(param_1 + 0x19c) != 0) {
    piVar2 = *(int **)(param_1 + 0x19c);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    piVar2 = *(int **)(param_1 + 0x19c);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  if (*(int *)(param_1 + 0x234) != 0) {
    piVar2 = *(int **)(param_1 + 0x234);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x234) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    piVar2 = *(int **)(param_1 + 0x234);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x234) = 0;
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  return;
}


