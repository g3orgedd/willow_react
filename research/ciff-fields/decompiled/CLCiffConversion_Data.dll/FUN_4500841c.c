// Source: CLCiffConversion_Data.dll @ 4500841c; FUN_4500841c

void __thiscall
FUN_4500841c(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4,
            int *param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (0xaaaaaa8 < *(uint *)((int)this + 4)) {
    FUN_450088df(param_5 + 4);
    FID_conflict__free(param_5);
                    /* WARNING: Subroutine does not return */
    FUN_45020fb5("map/set<T> too long");
  }
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) + 1;
  param_5[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = param_5;
    **(undefined4 **)this = param_5;
    *(int **)(*(int *)this + 8) = param_5;
  }
  else if (param_2 == '\0') {
    param_3[2] = param_5;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = param_5;
    }
  }
  else {
    *param_3 = param_5;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)param_5;
    }
  }
  iVar2 = param_5[1];
  piVar4 = param_5;
  do {
    if (*(char *)(iVar2 + 0xc) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = param_5;
      return;
    }
    piVar1 = (int *)piVar4[1];
    piVar3 = *(int **)piVar1[1];
    if (piVar1 == piVar3) {
      piVar3 = (int *)((undefined4 *)piVar1[1])[2];
      if ((char)piVar3[3] == '\0') {
LAB_450084c6:
        *(undefined1 *)(piVar1 + 3) = 1;
        *(undefined1 *)(piVar3 + 3) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        piVar4 = *(int **)(piVar4[1] + 4);
      }
      else {
        if (piVar4 == (int *)piVar1[2]) {
          FUN_45009054(this,(int)piVar1);
          piVar4 = piVar1;
        }
        *(undefined1 *)(piVar4[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
        FUN_45007a43(this,*(int **)(piVar4[1] + 4));
      }
    }
    else {
      if ((char)piVar3[3] == '\0') goto LAB_450084c6;
      if (piVar4 == (int *)*piVar1) {
        FUN_45007a43(this,piVar1);
        piVar4 = piVar1;
      }
      *(undefined1 *)(piVar4[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar4[1] + 4) + 0xc) = 0;
      FUN_45009054(this,*(int *)(piVar4[1] + 4));
    }
    iVar2 = piVar4[1];
  } while( true );
}


