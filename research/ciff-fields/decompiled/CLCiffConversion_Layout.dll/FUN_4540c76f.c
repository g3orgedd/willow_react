// Source: CLCiffConversion_Layout.dll @ 4540c76f; FUN_4540c76f

void __thiscall
FUN_4540c76f(void *this,uint param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_8 == 0) {
LAB_4540c823:
    *param_2 = param_4;
    if (param_7 == 1) {
      if (param_1 < *(uint *)((int)this + 4)) {
        iVar1 = *(int *)(*(int *)((int)this + 0xe4) + param_1 * 4);
      }
      *param_2 = (param_4 - iVar1) + param_6;
    }
    else if (param_7 == 2) {
      if (param_1 < *(uint *)((int)this + 4)) {
        iVar1 = *(int *)(*(int *)((int)this + 0xe4) + param_1 * 4);
      }
      *param_2 = ((uint)(param_6 - iVar1) >> 1) + param_4;
    }
  }
  else {
    if (param_8 == 1) {
      iVar2 = param_5 + param_6;
      *param_3 = iVar2;
      param_2 = param_3;
      if (param_7 != 1) {
LAB_4540c7cb:
        if (param_7 != 2) {
          return;
        }
        if (param_1 < *(uint *)((int)this + 4)) {
          iVar1 = *(int *)(*(int *)((int)this + 0xe4) + param_1 * 4);
        }
        *param_2 = iVar2 - ((uint)(param_6 - iVar1) >> 1);
        return;
      }
      param_4 = param_5;
      if (param_1 < *(uint *)((int)this + 4)) {
        iVar1 = *(int *)(*(int *)((int)this + 0xe4) + param_1 * 4);
      }
    }
    else {
      if (param_8 != 2) {
        param_4 = param_5;
        param_2 = param_3;
        if (param_8 != 3) {
          return;
        }
        goto LAB_4540c823;
      }
      iVar2 = param_4 + param_6;
      *param_2 = iVar2;
      if (param_7 != 1) goto LAB_4540c7cb;
      if (param_1 < *(uint *)((int)this + 4)) {
        iVar1 = *(int *)(*(int *)((int)this + 0xe4) + param_1 * 4);
      }
    }
    *param_2 = param_4 + iVar1;
  }
  return;
}


