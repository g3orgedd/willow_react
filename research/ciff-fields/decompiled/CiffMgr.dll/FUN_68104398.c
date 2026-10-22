// Source: CiffMgr.dll @ 68104398; FUN_68104398

undefined4 __thiscall FUN_68104398(void *this,LCID param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    uVar2 = 0;
    if (*(int *)((int)this + 0xc) == 0) {
      uVar2 = FUN_68104199(this,param_1);
    }
    *param_2 = *(undefined4 *)((int)this + 0xc);
    piVar1 = *(int **)((int)this + 0xc);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      uVar2 = 0;
    }
  }
  return uVar2;
}


