// Source: CiffMgr.dll @ 6810561b; FUN_6810561b

void __thiscall FUN_6810561b(void *this,undefined8 *param_1)

{
  if (*(uint *)((int)param_1 + 0x14) < 8) {
    FUN_68106abd(this,param_1,*(int *)(param_1 + 2) + 1);
  }
  else {
    if (this != (void *)0x0) {
      *(undefined4 *)this = *(undefined4 *)param_1;
    }
    *(undefined4 *)param_1 = 0;
  }
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = 7;
  *(undefined2 *)param_1 = 0;
  return;
}


