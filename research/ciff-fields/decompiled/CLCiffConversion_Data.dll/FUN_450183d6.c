// Source: CLCiffConversion_Data.dll @ 450183d6; FUN_450183d6

void __fastcall FUN_450183d6(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = *(int **)(param_1 + 0x2c);
  piVar1 = DAT_450538b4;
  piVar3 = DAT_450538b0;
  if (piVar2 != (int *)0x0) {
    for (; piVar1 = DAT_450538b4, piVar3 = DAT_450538b0, *piVar2 != 0; piVar2 = piVar2 + 9) {
      piVar1 = (int *)piVar2[4];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar2[4] = 0;
      (*(code *)piVar2[8])(0);
    }
  }
  for (; piVar3 < piVar1; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      (**(code **)(*piVar3 + 0x1c))(0);
      piVar1 = DAT_450538b4;
    }
  }
  FUN_4501839d(param_1);
  return;
}


