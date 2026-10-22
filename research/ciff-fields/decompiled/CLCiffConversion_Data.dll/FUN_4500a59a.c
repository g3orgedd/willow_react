// Source: CLCiffConversion_Data.dll @ 4500a59a; FUN_4500a59a

void __thiscall
FUN_4500a59a(void *this,undefined4 *param_1,char param_2,undefined4 *param_3,undefined8 *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if (0x3fffffd < *(uint *)((int)this + 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_45020fb5("map/set<T> too long");
  }
  piVar2 = FUN_4500a45d(this,param_4);
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  piVar2[1] = (int)param_3;
  if (param_3 == *(undefined4 **)this) {
    (*(undefined4 **)this)[1] = piVar2;
    **(undefined4 **)this = piVar2;
    *(int **)(*(int *)this + 8) = piVar2;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar2;
    if (param_3 == *(undefined4 **)(*(int *)this + 8)) {
      *(int **)(*(int *)this + 8) = piVar2;
    }
  }
  else {
    *param_3 = piVar2;
    if (param_3 == (undefined4 *)**(int **)this) {
      **(int **)this = (int)piVar2;
    }
  }
  iVar3 = piVar2[1];
  piVar5 = piVar2;
  do {
    if (*(char *)(iVar3 + 0xc) != '\0') {
      *(undefined1 *)(*(int *)(*(int *)this + 4) + 0xc) = 1;
      *param_1 = piVar2;
      return;
    }
    piVar1 = (int *)piVar5[1];
    piVar4 = *(int **)piVar1[1];
    if (piVar1 == piVar4) {
      piVar4 = (int *)((undefined4 *)piVar1[1])[2];
      if ((char)piVar4[3] == '\0') {
LAB_4500a649:
        *(undefined1 *)(piVar1 + 3) = 1;
        *(undefined1 *)(piVar4 + 3) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
        piVar5 = *(int **)(piVar5[1] + 4);
      }
      else {
        if (piVar5 == (int *)piVar1[2]) {
          FUN_45009054(this,(int)piVar1);
          piVar5 = piVar1;
        }
        *(undefined1 *)(piVar5[1] + 0xc) = 1;
        *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
        FUN_45007a43(this,*(int **)(piVar5[1] + 4));
      }
    }
    else {
      if ((char)piVar4[3] == '\0') goto LAB_4500a649;
      if (piVar5 == (int *)*piVar1) {
        FUN_45007a43(this,piVar1);
        piVar5 = piVar1;
      }
      *(undefined1 *)(piVar5[1] + 0xc) = 1;
      *(undefined1 *)(*(int *)(piVar5[1] + 4) + 0xc) = 0;
      FUN_45009054(this,*(int *)(piVar5[1] + 4));
    }
    iVar3 = piVar5[1];
  } while( true );
}


