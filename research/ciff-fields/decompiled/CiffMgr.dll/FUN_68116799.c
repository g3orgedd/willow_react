// Source: CiffMgr.dll @ 68116799; FUN_68116799

undefined4 FUN_68116799(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else if (param_2 < 1) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = 0x80004005;
    piVar2 = *(int **)(param_1 + 4);
    while ((param_2 = param_2 + -1, piVar2 != *(int **)(param_1 + 8) && (0 < param_2))) {
      piVar2 = piVar2 + 1;
    }
    if (piVar2 != *(int **)(param_1 + 8)) {
      uVar1 = FUN_68116264(param_3,piVar2);
    }
  }
  return uVar1;
}


