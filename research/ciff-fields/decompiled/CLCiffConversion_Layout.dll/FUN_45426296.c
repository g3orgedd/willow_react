// Source: CLCiffConversion_Layout.dll @ 45426296; FUN_45426296

int __thiscall FUN_45426296(void *this,int *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_4 == 3) {
    uVar3 = (int)param_2 - (int)param_1 >> 2;
    lVar2 = (ulonglong)uVar3 * 4;
    iVar4 = FUN_4542ee7f(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
    *(int *)((int)this + 8) = iVar4;
    *(int *)((int)this + 0x10) = iVar4;
    if (iVar4 == 0) {
      return -0x7ff8fff2;
    }
    for (; param_1 != param_2; param_1 = param_1 + 1) {
      iVar4 = FUN_45428489(*(int **)((int)this + 0x10),param_1);
      if (iVar4 < 0) {
        piVar5 = *(int **)((int)this + 8);
        while (piVar5 < *(int **)((int)this + 0x10)) {
          piVar1 = (int *)*piVar5;
          piVar5 = piVar5 + 1;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        FID_conflict__free(*(void **)((int)this + 8));
        *(undefined4 *)((int)this + 0x10) = 0;
        *(undefined4 *)((int)this + 0xc) = 0;
        *(undefined4 *)((int)this + 8) = 0;
        return iVar4;
      }
      *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 4;
    }
    param_2 = (int *)(*(int *)((int)this + 8) + uVar3 * 4);
  }
  else {
    *(int **)((int)this + 8) = param_1;
  }
  *(int **)((int)this + 0xc) = param_2;
  FUN_45413189((void *)((int)this + 4),param_3);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)((int)this + 8);
  *(int *)((int)this + 0x14) = param_4;
  return 0;
}


