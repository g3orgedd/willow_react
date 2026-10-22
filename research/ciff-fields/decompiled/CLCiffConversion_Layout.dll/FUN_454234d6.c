// Source: CLCiffConversion_Layout.dll @ 454234d6; FUN_454234d6

void __thiscall FUN_454234d6(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *_Memory;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  _Memory = param_2;
  FUN_45409a25((int *)&param_2);
  piVar4 = (int *)*_Memory;
  if (*(char *)((int)piVar4 + 0xd) == '\0') {
    piVar5 = piVar4;
    if ((*(char *)(_Memory[2] + 0xd) != '\0') || (piVar5 = (int *)param_2[2], param_2 == _Memory))
    goto LAB_45423510;
    piVar4[1] = (int)param_2;
    *param_2 = *_Memory;
    piVar4 = param_2;
    if (param_2 != (int *)_Memory[2]) {
      piVar4 = (int *)param_2[1];
      if (*(char *)((int)piVar5 + 0xd) == '\0') {
        piVar5[1] = (int)piVar4;
      }
      *piVar4 = (int)piVar5;
      param_2[2] = _Memory[2];
      *(int **)(_Memory[2] + 4) = param_2;
    }
    if (*(int **)(*(int *)this + 4) == _Memory) {
      *(int **)(*(int *)this + 4) = param_2;
    }
    else {
      piVar2 = (int *)_Memory[1];
      if ((int *)*piVar2 == _Memory) {
        *piVar2 = (int)param_2;
      }
      else {
        piVar2[2] = (int)param_2;
      }
    }
    param_2[1] = _Memory[1];
    iVar1 = param_2[3];
    *(char *)(param_2 + 3) = (char)_Memory[3];
    *(char *)(_Memory + 3) = (char)iVar1;
  }
  else {
    piVar5 = (int *)_Memory[2];
LAB_45423510:
    piVar4 = (int *)_Memory[1];
    if (*(char *)((int)piVar5 + 0xd) == '\0') {
      piVar5[1] = (int)piVar4;
    }
    if (*(int **)(*(int *)this + 4) == _Memory) {
      *(int **)(*(int *)this + 4) = piVar5;
    }
    else if ((int *)*piVar4 == _Memory) {
      *piVar4 = (int)piVar5;
    }
    else {
      piVar4[2] = (int)piVar5;
    }
    if ((int *)**(int **)this == _Memory) {
      piVar2 = piVar4;
      if (*(char *)((int)piVar5 + 0xd) == '\0') {
        piVar2 = piVar5;
        for (piVar3 = (int *)*piVar5; *(char *)((int)piVar3 + 0xd) == '\0'; piVar3 = (int *)*piVar3)
        {
          piVar2 = piVar3;
        }
      }
      **(undefined4 **)this = piVar2;
    }
    if (*(int **)(*(int *)this + 8) == _Memory) {
      piVar2 = piVar4;
      if (*(char *)((int)piVar5 + 0xd) == '\0') {
        piVar2 = piVar5;
        for (piVar3 = (int *)piVar5[2]; *(char *)((int)piVar3 + 0xd) == '\0';
            piVar3 = (int *)piVar3[2]) {
          piVar2 = piVar3;
        }
      }
      *(int **)(*(int *)this + 8) = piVar2;
    }
  }
  if ((char)_Memory[3] != '\x01') {
LAB_454236f5:
    FUN_45409ac2(_Memory + 4,0);
    FID_conflict__free(_Memory);
    if (*(int *)((int)this + 4) != 0) {
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
    }
    *param_1 = param_2;
    return;
  }
LAB_454236ae:
  piVar2 = piVar4;
  if ((piVar5 == *(int **)(*(int *)this + 4)) || ((char)piVar5[3] != '\x01')) goto LAB_454236f1;
  piVar4 = (int *)*piVar2;
  if (piVar5 == piVar4) {
    piVar4 = (int *)piVar2[2];
    if ((char)piVar4[3] == '\0') {
      *(undefined1 *)(piVar4 + 3) = 1;
      *(undefined1 *)(piVar2 + 3) = 0;
      FUN_45407dea(this,(int)piVar2);
      piVar4 = (int *)piVar2[2];
    }
    if (*(char *)((int)piVar4 + 0xd) == '\0') {
      if ((*(char *)(*piVar4 + 0xc) != '\x01') || (*(char *)(piVar4[2] + 0xc) != '\x01')) {
        if (*(char *)(piVar4[2] + 0xc) == '\x01') {
          *(undefined1 *)(*piVar4 + 0xc) = 1;
          *(undefined1 *)(piVar4 + 3) = 0;
          FUN_45409c55(this,piVar4);
          piVar4 = (int *)piVar2[2];
        }
        *(char *)(piVar4 + 3) = (char)piVar2[3];
        *(undefined1 *)(piVar2 + 3) = 1;
        *(undefined1 *)(piVar4[2] + 0xc) = 1;
        FUN_45407dea(this,(int)piVar2);
        goto LAB_454236f1;
      }
LAB_454236a5:
      *(undefined1 *)(piVar4 + 3) = 0;
    }
  }
  else {
    if ((char)piVar4[3] == '\0') {
      *(undefined1 *)(piVar4 + 3) = 1;
      *(undefined1 *)(piVar2 + 3) = 0;
      FUN_45409c55(this,piVar2);
      piVar4 = (int *)*piVar2;
    }
    if (*(char *)((int)piVar4 + 0xd) == '\0') {
      if ((*(char *)(piVar4[2] + 0xc) == '\x01') && (*(char *)(*piVar4 + 0xc) == '\x01'))
      goto LAB_454236a5;
      if (*(char *)(*piVar4 + 0xc) == '\x01') {
        *(undefined1 *)(piVar4[2] + 0xc) = 1;
        *(undefined1 *)(piVar4 + 3) = 0;
        FUN_45407dea(this,(int)piVar4);
        piVar4 = (int *)*piVar2;
      }
      *(char *)(piVar4 + 3) = (char)piVar2[3];
      *(undefined1 *)(piVar2 + 3) = 1;
      *(undefined1 *)(*piVar4 + 0xc) = 1;
      FUN_45409c55(this,piVar2);
LAB_454236f1:
      *(undefined1 *)(piVar5 + 3) = 1;
      goto LAB_454236f5;
    }
  }
  piVar4 = (int *)piVar2[1];
  piVar5 = piVar2;
  goto LAB_454236ae;
}


