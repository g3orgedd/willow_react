// Source: CLCSSmallBarcode.dll @ 4203407d; FUN_4203407d

int __thiscall FUN_4203407d(void *this,int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  void *this_00;
  int iVar3;
  int iVar4;
  
  *param_2 = 0x1d;
  iVar4 = -0x7fffbffd;
  if (*param_1 != 0) {
    puVar1 = (undefined4 *)((int)this + 200);
    SysFreeString((BSTR)*puVar1);
    *puVar1 = 0;
    iVar4 = (**(code **)(*(int *)*param_1 + 0x98))((int *)*param_1,puVar1);
    if (-1 < iVar4) {
      *(undefined4 *)((int)this + 0xb8) = 1;
      iVar4 = (**(code **)(*(int *)*param_1 + 0x1b4))
                        ((int *)*param_1,(undefined4 *)((int)this + 0xb8));
      if (-1 < iVar4) {
        piVar2 = (int *)((int)this + 0xbc);
        *piVar2 = 0;
        iVar4 = (**(code **)(*(int *)*param_1 + 0x1ac))((int *)*param_1,piVar2);
        if (-1 < iVar4) {
          if ((*piVar2 < 0) || (0x28 < *piVar2)) {
            *piVar2 = 0;
          }
          if (*piVar2 == 0) {
            this_00 = *(void **)((int)this + 0xf0);
            if (this_00 == (void *)0x0) {
              return iVar4;
            }
            if (*(int *)((int)this + 0xf4) == 0) {
              iVar4 = FUN_42035049(this_00,(int *)((int)this + 200),(byte *)0x0,
                                   *(int *)((int)this + 0xb8));
            }
            else {
              iVar4 = FUN_42034eaa(this_00,(int *)((int)this + 200),(byte *)0x0,
                                   *(int *)((int)this + 0xb8));
            }
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar3 = FUN_420351bb(*(int *)((int)this + 0xf0));
          }
          else {
            iVar3 = *piVar2 * 4 + 0x11;
          }
          *param_2 = iVar3;
        }
      }
    }
  }
  return iVar4;
}


