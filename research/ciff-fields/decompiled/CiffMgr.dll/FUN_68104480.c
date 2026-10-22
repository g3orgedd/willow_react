// Source: CiffMgr.dll @ 68104480; FUN_68104480

void __thiscall
FUN_68104480(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,LCID param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int *piVar1;
  
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    FUN_68104199(this,param_4);
  }
  piVar1 = *(int **)((int)this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(piVar1,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
  }
  return;
}


